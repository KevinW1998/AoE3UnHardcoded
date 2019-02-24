import os
import sys
import logging
import pprint

from enum import Enum
from optparse import OptionParser
from clang.cindex import Index, Config, CursorKind

import bang_native_file_change_detector
from bang_native_generator import BangNativeGenerator
from bang_native_parser import BangNativeParser
from syspaths import ccsyspaths_improved


def find_and_parse_class(cursor, class_type, class_name):
    """
    Goes through all cursors and tries to fetch the class
    @param cursor: The top-most cursor
    @param class_type: The type of the class to parse, must be CursorKind.STRUCT_DECL or CursorKind.CLASS_DECL
    @param class_name: The name of the class to find
    @type cursor: Cursor
    @type class_type: CursorKind
    @type class_name: str
    @return: The parsed class
    @rtype: LunaClass
    """

    def get_info(node, max_depth, depth=0):
        if max_depth is not None and depth >= max_depth:
            children = None
        else:
            children = [get_info(c, max_depth, depth + 1)
                        for c in node.get_children()]
        return {'kind': node.kind,
                'start': node.extent.start,
                'end': node.extent.end,
                'spelling': node.spelling,
                'type': node.type.kind,
                'is_definition': node.is_definition(),
                'children': children}

    def dump_cursor(cursor_to_dump):
        print(str(get_info(cursor_to_dump, 10)))

    def has_fields(class_cursor):
        """
        @param class_cursor: The class cursor
        @type class_cursor: Cursor
        @return: True, if the class cursor has fields
        @rtype: bool
        """
        for nextPossibleField in class_cursor.get_children():  # type: Cursor
            if nextPossibleField.kind == CursorKind.FIELD_DECL:
                return True
        return False

    if cursor.spelling == class_name and cursor.kind == class_type:
        return cursor

    for nextChild in cursor.get_children():  # type: Cursor
        call_result = find_and_parse_class(nextChild, class_type, class_name)
        if call_result is not None:
            return call_result


def create_dirs_for_filename(filename):
    try:
        os.makedirs(os.path.dirname(filename))
    except os.error:
        pass


def main():
    parser = OptionParser("usage: %prog input-file-list [options]")
    parser.add_option("-i", "--input-folder", dest="input",
                      help="The input folder, where all header files should be extracted for parsing", type="string")
    parser.add_option("-l", "--clang-bin-path", dest="clang_path",
                      help="The path to the libclang file", type="string")
    parser.add_option("--cache-file", dest="cache_file",
                      help="The json file for the parsing cache", type="string")
    parser.add_option("--generate-header-filename", dest="gen_header",
                      help="The filename for the generated header file", type="string", default="output/SymBangTableGenerated.h")
    parser.add_option("--generate-def-filename", dest="gen_def",
                      help="The filename for the generated def file", type="string", default="output/BangNativeGenerated.def")
    parser.add_option("--addr-alloc", dest="ptr_alloc",
                      help="The address to allocation", type=int, default=0x00767BD3)
    parser.add_option("--addr-alloc-array", dest="ptr_alloc_array",
                      help="The address to array allocation", type=int, default=0x0076861D)
    parser.add_option("--addr-delete", dest="ptr_delete",
                      help="The address to memory deletion", type=int, default=0x00767B0D)
    parser.disable_interspersed_args()
    (options_result, args) = parser.parse_args()

    # Check for args
    # 1. Input file
    if len(args) <= 0:
        parser.error("No input file list")

    # Fetch args
    input_file = args[0]

    # Read all
    class_names = []
    try:
        with open(input_file) as f:
            class_names = f.readlines()
    except IOError:
        parser.error("Failed to open file " + input_file)
    class_names = [x.strip() for x in class_names]  # Cleanup string
    class_names = list(filter(None, class_names))  # Remove all empty strings

    # Options
    # output_dir = options_result.output
    # if output_dir is None:
        # output_dir = os.path.normpath(os.path.join(os.path.dirname(os.path.realpath(sys.argv[0])), "output"))
    create_dirs_for_filename(options_result.gen_header)
    create_dirs_for_filename(options_result.gen_def)
    opt_input_folder = options_result.input or '.'
    opt_cache_folder = options_result.cache_file or os.path.join(options_result.gen_header, "gen-cache.json")

    # Check if generating is needed
    if not bang_native_file_change_detector.has_file_changes(opt_input_folder, class_names,
                                                             os.path.normpath(os.path.join(opt_input_folder, ".bang-hash"))):
        print("Skipping as no file changes has been done")
        return

    args = '-x c++ --std=c++17 -m32 -D__BANG_NATIVE_CODE_GENERATOR__'.split()
    parser = BangNativeParser(options_result.clang_path, args, opt_cache_folder)
    parser.read_entries(opt_input_folder, class_names)

    if not parser.has_read_all_from_cache():
        generator = BangNativeGenerator(options_result.gen_header, options_result.gen_def,
                                        options_result.ptr_alloc, options_result.ptr_alloc_array, options_result.ptr_delete)
        generator.generate(parser.get_parsed_classes())
    else:
        print("Skipping as everything has been read from cache, no generation needed")

    bang_native_file_change_detector.write_file_change_hash(opt_input_folder, class_names,
                                                      os.path.normpath(os.path.join(opt_input_folder, ".bang-hash")))

if __name__ == '__main__':
    main()
