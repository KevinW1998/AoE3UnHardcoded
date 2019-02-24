import logging
import os
import pprint
from enum import Enum

from clang.cindex import Config, CursorKind, Index, TypeKind

from bang_native_utils import crc
from syspaths import ccsyspaths_improved

# Define logger
module_logger = logging.getLogger('bang_native_gen_binding')


def _helper_get_info(node, max_depth, depth=0):
    if max_depth is not None and depth >= max_depth:
        children = None
    else:
        children = [_helper_get_info(c, max_depth, depth + 1)
                    for c in node.get_children()]
    return {'kind': node.kind,
            'start': node.extent.start,
            'end': node.extent.end,
            'spelling': node.spelling,
            'type': node.type.kind,
            'type.spelling': node.type.spelling,
            'is_definition': node.is_definition(),
            'definition': node.get_definition(),
            'result_type': node.result_type,
            'result_type.spelling': node.result_type.spelling,
            'children': children}

# https://blog.mosthege.net/2016/11/12/json-deserialization-of-nested-objects/

class BangNativeReg(Enum):
    EAX = 1,
    ECX = 2,
    EDX = 3,
    EBX = 4,
    ESI = 5,
    EDI = 6,
    AX = 7,
    CX = 8,
    DX = 9,
    BX = 10,
    SI = 11,
    DI = 12,
    AH = 13,
    AL = 14,
    CH = 15,
    CL = 16,
    DH = 17,
    DL = 18,
    BH = 19,
    BL = 20,
    GENERIC_PARAM = 21, # same as in X86Register
    STACK = 21


class BangNativeMethodType(Enum):
    METHOD = 1,
    CONSTRUCTOR = 2,
    DESTRUCTOR = 3


class BangNativeTypeEntry:
    def __init__(self, type_spelling: str, is_pointer: bool, type_kind: TypeKind, type_size: int):
        self.type_spelling = type_spelling
        self.is_pointer = is_pointer
        self.type_kind = type_kind
        self.type_size = type_size

    def get_primitive(self):
        if self.is_pointer or (self.type_kind == TypeKind.RECORD and self.type_size == 4):
            return 'void*'
        return self.type_spelling

    @staticmethod
    def from_clang_type_param(clang_type_param):
        return BangNativeTypeEntry(
            clang_type_param.spelling,
            clang_type_param.kind == TypeKind.POINTER or clang_type_param.kind == TypeKind.LVALUEREFERENCE,
            clang_type_param.kind,
            clang_type_param.get_size())


    def __str__(self):
        return self.type_spelling


class BangNativeEntry:
    def __init__(self, class_name: str, method_name: str, method_mangling: str, method_type: BangNativeMethodType,
                 binding_address: int, custom_return_register: BangNativeReg, custom_param_registers: [BangNativeReg],
                 return_type: BangNativeTypeEntry, param_types: [BangNativeTypeEntry],
                 callee_cleanups: bool, is_virtual: bool):
        self.class_name = class_name
        self.method_name = method_name
        self.method_mangling = method_mangling
        self.method_type = method_type
        self.binding_address = binding_address
        self.custom_return_register = custom_return_register
        self.custom_param_registers = custom_param_registers
        self.return_type = return_type
        self.param_types = param_types
        self.callee_cleanups = callee_cleanups
        self.is_virtual = is_virtual

    def __repr__(self):
        return "class: %s, method: %s, mangling: %s, type: %s, binding address: %x, return reg: %s, params: %s" % (
            self.class_name, self.method_name, self.method_mangling, self.method_type, self.binding_address,
            self.custom_return_register, self.custom_param_registers)


class BangNativeClass:
    def __init__(self, entries: [BangNativeEntry], file_hash: str):
        self.entries = entries
        self.file_hash = file_hash


class BangNativeParser:
    def __init__(self, clang_path, args, cache_folder):
        self._clang_path = 'clang++'
        if clang_path is not None:
            Config.set_library_path(clang_path)
            self._clang_path = os.path.normpath(os.path.join(clang_path, "clang++"))

        syspath = ccsyspaths_improved.system_include_paths(self._clang_path)
        incargs = [b'-I' + inc for inc in syspath]
        args = args + incargs

        self._args = args
        self._parsed_classes = {}
        self._cache_folder = cache_folder

    # == UTILITY FUNCTIONS ==
    def _cursor_has_child_types(self, class_cursor, child_types):
        for nextPossibleField in class_cursor.get_children():  # type: Cursor
            if nextPossibleField.kind in child_types:
                return True
        return False

    # == PARSE/GENERATE CLASS ==
    def _has_dll_import(self, class_cursor):
        return self._cursor_has_child_types(class_cursor, [CursorKind.DLLIMPORT_ATTR])

    def _parse_register_attr(self, class_cursor, method_cursor, reg_native_raw_str):
        return_reg_str = reg_native_raw_str
        if not return_reg_str.startswith('RegGen::'):
            raise RuntimeError(
                'Invalid register value %s for class %s function %s. Be sure that it starts with "RegGen::"' % (
                    return_reg_str, class_cursor.spelling, method_cursor.spelling))
        return_reg_str_clean = return_reg_str.split('::')[-1]
        try:
            return BangNativeReg[return_reg_str_clean]
        except KeyError as kerr:
            raise RuntimeError(
                'Invalid register %s for class %s function %s. Be sure to use a valid register name!' % (
                    return_reg_str_clean, class_cursor.spelling, method_cursor.spelling))

    def _parse_class_cursor(self, class_cursor, precalc_hash):
        parsed_entries = []
        pp = pprint.PrettyPrinter(indent=2)
        # pp.pprint(_helper_get_info(class_cursor, 10))
        # TODO: Do proper destructor binding

        # Validate that class has dll import specifier
        # if not self._has_dll_import(class_cursor):
        # raise RuntimeError('Class %s has not the dllimport specitifier' + class_cursor.spelling)

        # Collect all methods
        method_cursors = list(filter(lambda x:
                                     x.kind == CursorKind.CXX_METHOD or
                                     x.kind == CursorKind.CONSTRUCTOR or
                                     x.kind == CursorKind.DESTRUCTOR,
                                     class_cursor.get_children()))

        # Parse constructors, destructor, methods add collect attributes
        for method_cursor in method_cursors:
            # Get all elements which starts with the prefix 'bang_native_arg$$'
            # and remove the prefix in one go (so bang_native_arg$$RegGen::EAX --> RegGen::EAX)
            # if "addBMode" in method_cursor.spelling:
            # pp.pprint(_helper_get_info(method_cursor, 10))
            # print(len(list(filter(lambda x: x.kind == CursorKind.ANNOTATE_ATTR and x.spelling.startswith(
            #                             'bang_native_arg$$'),
            #                                method_cursor.get_children()))))
            method_attributes = list(map(lambda x: x.spelling.split('$$')[-1],
                                         filter(lambda x: x.kind == CursorKind.ANNOTATE_ATTR and x.spelling.startswith(
                                             'bang_native_arg$$'),
                                                method_cursor.get_children())))[::-1]

            if len(method_attributes) <= 0:
                module_logger.warning('No attributes for class %s function %s, skipping...' % (
                    class_cursor.spelling, method_cursor.spelling))
                continue

            # 1. Get binding address
            binding_addr_hex_str = method_attributes[0]
            binding_addr_int_val = 0
            try:
                binding_addr_int_val = int(binding_addr_hex_str, 16)
            except ValueError as err:
                raise RuntimeError('Invalid binding hex addr %s for class %s function %s. Check value' % (
                    binding_addr_hex_str, class_cursor.spelling, method_cursor.spelling))

            # 2. Get optional return register
            return_reg = BangNativeReg.EAX
            if len(method_attributes) >= 2:
                return_reg = self._parse_register_attr(class_cursor, method_cursor, method_attributes[1])

            # 3. Get parameter registers
            param_reg_list = []
            # if "addBMode" in method_cursor.spelling:
            # print(method_attributes)
            for method_attr_reg_param_index in range(2, len(method_attributes)):
                method_attr_reg_param = method_attributes[method_attr_reg_param_index]
                param_reg_list.append(self._parse_register_attr(class_cursor, method_cursor, method_attr_reg_param))

            # 4. Get method type
            method_type = BangNativeMethodType.METHOD
            if method_cursor.kind == CursorKind.CONSTRUCTOR:
                method_type = BangNativeMethodType.CONSTRUCTOR
            elif method_cursor.kind == CursorKind.DESTRUCTOR:
                method_type = BangNativeMethodType.DESTRUCTOR

            # 5. Get param types
            method_params = list(map(lambda x: BangNativeTypeEntry.from_clang_type_param(x.type),
                                     filter(lambda x: x.kind == CursorKind.PARM_DECL, method_cursor.get_children())))

            # 6. Check if the type signature has varargs, if so, then the callee does not cleanup
            callee_cleanups = '...' not in method_cursor.type.spelling

            # 7. Check if virtual
            is_virtual = method_cursor.is_virtual_method()

            parsed_entries.append(
                BangNativeEntry(class_cursor.spelling, method_cursor.spelling, method_cursor.mangled_name,
                                method_type, binding_addr_int_val, return_reg, param_reg_list,
                                BangNativeTypeEntry.from_clang_type_param(method_cursor.result_type), method_params,
                                callee_cleanups, is_virtual))
            # print(method_attributes)
            # for method_attr in method_attributes:
            # print(method_attr)

        # Add to all
        self._parsed_classes[class_cursor.spelling] = BangNativeClass(parsed_entries, precalc_hash)

    # == FIND/PARSE START ==
    def _has_fields_or_methods(self, class_cursor):
        """
        @param class_cursor: The class cursor
        @type class_cursor: Cursor
        @return: True, if the class cursor has fields
        @rtype: bool
        """
        return self._cursor_has_child_types(class_cursor, [CursorKind.FIELD_DECL, CursorKind.CXX_METHOD])

    def _find_entry_recursive(self, cursor, class_to_find):
        if cursor.spelling == class_to_find and cursor.kind == CursorKind.CLASS_DECL and self._has_fields_or_methods(
                cursor):
            return cursor

        for nextChild in cursor.get_children():  # type: Cursor
            call_result = self._find_entry_recursive(nextChild, class_to_find)
            if call_result is not None:
                return call_result

    def get_parsed_classes(self):
        return self._parsed_classes

    def has_read_all_from_cache(self):
        return False

    # == FIND/PARSE END ==



    def read_entries(self, input_folder, input_list):
        for input_class_name in input_list:
            next_path = os.path.normpath(os.path.join(input_folder, input_class_name + ".h"))

            cppify_index = Index.create()
            indexed_file = cppify_index.parse(next_path, self._args)

            if not indexed_file:
                raise RuntimeError("Failed to load header file " + next_path)

            # Debug output
            # pp = pprint.PrettyPrinter(indent=2)
            # pp.pprint(_helper_get_info(indexed_file.cursor, 10))

            # Find
            cursor_for_class = self._find_entry_recursive(indexed_file.cursor, input_class_name)
            if cursor_for_class is None:
                raise RuntimeError("Failed to find class " + input_class_name)

            # Parse
            self._parse_class_cursor(cursor_for_class, crc(next_path))

            # TODO: Write to cache file
