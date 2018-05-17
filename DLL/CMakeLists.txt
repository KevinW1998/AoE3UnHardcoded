
# Get the files
ucm_add_dirs(. TO UHC_DLL_FILES RECURSIVE ADDITIONAL_EXT def rc asm)
ucm_remove_directories(zydis FROM UHC_DLL_FILES)

# Add to library project
add_library(UHCDLL SHARED ${UHC_DLL_FILES})

target_include_directories(UHCDLL PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/zydis/include)
target_include_directories(UHCDLL PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/zydis/msvc)

target_link_libraries(UHCDLL PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/bin/Zydis.lib)