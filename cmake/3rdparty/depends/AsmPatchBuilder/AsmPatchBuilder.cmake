include(ExternalProject)
find_package(Git REQUIRED)

ExternalProject_Add(
    AsmPatchBuilder
    PREFIX ${CMAKE_BINARY_DIR}/external/AsmPatchBuilder
    GIT_REPOSITORY https://github.com/KevinW1998/AsmPatchBuilder.git
    TIMEOUT 10
    BUILD_COMMAND ""
    CONFIGURE_COMMAND ""
    INSTALL_COMMAND ""
    TEST_COMMAND ""
    LOG_DOWNLOAD ON
)

# Expose required variable (CATCH_INCLUDE_DIR) to parent scope
ExternalProject_Get_Property(AsmPatchBuilder source_dir)
message(STATUS "AsmPatchBuilder source dir is: ${source_dir}")

set(ASM_PATCH_BUILDER_INCLUDE_DIR ${source_dir} CACHE INTERNAL "Path to include folder for AsmPatchBuilder")

function(asmpatchbuilder_add_dependency target)
    target_include_directories(${target} PRIVATE ${ASM_PATCH_BUILDER_INCLUDE_DIR})
    add_dependencies(${target} AsmPatchBuilder)
endfunction()
