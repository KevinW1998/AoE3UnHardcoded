
# Get the files
ucm_add_dirs(. TO UHC_DLL_FILES RECURSIVE ADDITIONAL_EXT def rc asm)

# DumpSyscall has been removed / cannot be built?
ucm_remove_files(DumpSyscall.asm DumpSyscall.cpp FROM UHC_DLL_FILES)

# Add to library project
add_library(UHCDLL SHARED ${UHC_DLL_FILES})

# == Linker flags ==
ucm_add_linker_flags(SHARED "/SAFESEH:NO" "/DELAYLOAD:Bang.dll")

# == Dependencies ==
zydis_add_dependency(UHCDLL)
remod_add_dependency(UHCDLL)
asmpatchbuilder_add_dependency(UHCDLL)
add_dependencies(UHCDLL BangNative)
target_link_libraries(UHCDLL BangNative)
target_link_libraries(UHCDLL "${UHC_BANG_NATIVE_FAKE_DLL_FOLDER}/Bang.lib")

# == Set Output Name ==
set_target_properties(UHCDLL PROPERTIES OUTPUT_NAME "UHC")

# == Install == 
install(TARGETS UHCDLL
    RUNTIME DESTINATION bin)


