
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


