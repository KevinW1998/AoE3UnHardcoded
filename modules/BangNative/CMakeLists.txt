
# Get the files
ucm_add_dirs(src TO UHC_BANG_NATIVE_FILES RECURSIVE FILTER_POP 1 ADDITIONAL_EXT def rc asm)

# Add to library project
add_library(BangNative STATIC ${UHC_BANG_NATIVE_FILES})

target_include_directories(BangNative PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Allowed to be used in other proects
set(UHC_BANG_NATIVE_FAKE_DLL_FOLDER "${CMAKE_CURRENT_SOURCE_DIR}/generated" PARENT_SCOPE)
set(UHC_BANG_NATIVE_FAKE_DLL_FOLDER_INTERNAL "${CMAKE_CURRENT_SOURCE_DIR}/generated")

# Add the fake DLL for loading
add_custom_command(TARGET BangNative
	PRE_BUILD
	COMMAND lib /DEF:Bang.def /MACHINE:X86
	DEPENDS Bang.def
	WORKING_DIRECTORY "${UHC_BANG_NATIVE_FAKE_DLL_FOLDER_INTERNAL}"
)

# == Setup binding generator == 
set(BANG_NATIVE_ALLOC_PTR 0x398)
set(BANG_NATIVE_ALLOC_ARRAY_PTR 0x398)
set(BANG_NATIVE_DELETE_PTR 0x548)


# Find Python
set(PYTHON_VERSION_MAJOR 3) # Ensure python 3
find_package(PythonInterp 3)
if(${PYTHONINTERP_FOUND})
	# Try to find clang folder
	if(IS_DIRECTORY ${BANG_NATIVE_CLANG_PATH})
		set(OPT_CLANG_OUT_PATH "${BANG_NATIVE_CLANG_PATH}/clang.exe")
	else()
		find_program(OPT_CLANG_OUT_PATH clang clang++)	
	endif()
	
	if(EXISTS ${OPT_CLANG_OUT_PATH})
		get_filename_component(CLANG_BIN_PATH ${OPT_CLANG_OUT_PATH} DIRECTORY)
		add_custom_target(BangNativeAPIGenerator ALL "${PYTHON_EXECUTABLE}" "tools/BangNativeGenBindings/bang_native_gen_bindings_main.py" "--clang-bin-path=${CLANG_BIN_PATH}" "--input-folder=src/native" "--generate-header-filename=src/BangSymTableGenerated.h" "--generate-def-filename=generated/Bang.def" "--addr-alloc=${BANG_NATIVE_ALLOC_PTR}" "--addr-alloc-array=${BANG_NATIVE_ALLOC_ARRAY_PTR}" "--addr-delete=${BANG_NATIVE_DELETE_PTR}" "BangNativeClasses.txt" WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
		add_dependencies(BangNative BangNativeAPIGenerator)
	else()
		message(WARNING "Failed to find clang. Consider setting BANG_NATIVE_CLANG_PATH as hint")
	endif()
else()
	message(WARNING "Failed to find python. BangNative will not automatically generate bindings. Beware!")
endif()






