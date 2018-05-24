include(ExternalProject)
find_package(Git REQUIRED)

set(REMOD_INSTALL_DIR ${CMAKE_BINARY_DIR}/external/remod-install)
set(REMOD_INCLUDE_DIR ${REMOD_INSTALL_DIR}/include)
set(REMOD_LIBRARY_DIR ${REMOD_INSTALL_DIR}/lib)
set(REMOD_LIBRARY_FILES ${REMOD_LIBRARY_DIR}/ReModCore.lib)

ExternalProject_Add(
    remod
    PREFIX ${CMAKE_BINARY_DIR}/external/remod
    GIT_REPOSITORY https://github.com/KevinW1998/ReMod-Core.git
	# GIT_TAG v2.0.1 # No git tag for now...
    TIMEOUT 10
    # UPDATE_COMMAND "git pull"
    LOG_DOWNLOAD ON
    BUILD_IN_SOURCE 1
    CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${REMOD_INSTALL_DIR}"
)

function(remod_add_dependency target)
    target_include_directories(${target} PUBLIC ${REMOD_INCLUDE_DIR})
    add_dependencies(${target} remod)
    target_link_libraries(${target} ${REMOD_LIBRARY_FILES})
endfunction()


