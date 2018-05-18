
# Get the files
ucm_add_dirs(. TO UHC_DLL_FILES RECURSIVE ADDITIONAL_EXT def rc asm)

# DumpSyscall has been removed / cannot be built?
ucm_remove_files(DumpSyscall.asm DumpSyscall.cpp FROM UHC_DLL_FILES)

# Add to library project
add_library(UHCDLL SHARED ${UHC_DLL_FILES})

# == Linker flags ==
ucm_add_linker_flags(SHARED "/SAFESEH:NO")

# == Dependencies ==
zydis_add_dependency(UHCDLL)

# == Install == 
install(TARGETS UHCDLL
    RUNTIME DESTINATION bin)
