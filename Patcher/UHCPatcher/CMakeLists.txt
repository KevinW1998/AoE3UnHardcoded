
# Get the files
ucm_add_dirs(. TO UHC_PATCHER_FILES RECURSIVE ADDITIONAL_EXT def rc)

# Add to library project
add_executable(UHCPatcher WIN32 ${UHC_PATCHER_FILES})

