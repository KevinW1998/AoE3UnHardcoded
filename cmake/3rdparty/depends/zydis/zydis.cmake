include(ExternalProject)
find_package(Git REQUIRED)

set(ZYDIS_INSTALL_DIR ${CMAKE_BINARY_DIR}/external/zydis-install)
set(ZYDIS_INCLUDE_DIR ${ZYDIS_INSTALL_DIR}/include)
set(ZYDIS_LIBRARY_DIR ${ZYDIS_INSTALL_DIR}/lib)
set(ZYDIS_LIBRARY_FILES ${ZYDIS_LIBRARY_DIR}/Zydis.lib)

ExternalProject_Add(
    zydis
    PREFIX ${CMAKE_BINARY_DIR}/external/zydis
    GIT_REPOSITORY https://github.com/zyantific/zydis.git
	GIT_TAG v2.0.1
    TIMEOUT 10
    UPDATE_COMMAND ""
    LOG_DOWNLOAD ON
    BUILD_IN_SOURCE 1
    CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${ZYDIS_INSTALL_DIR}"
)

function(zydis_add_dependency target)
    target_include_directories(${target} PRIVATE ${ZYDIS_INCLUDE_DIR})
    add_dependencies(${target} zydis)
    target_link_libraries(${target} ${ZYDIS_LIBRARY_FILES})
endfunction()


