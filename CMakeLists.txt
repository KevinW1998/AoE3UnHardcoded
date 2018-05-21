# Header
cmake_minimum_required (VERSION 3.7.2)
project(UHC)

# Enable asm, we need it!
# enable_language(ASM)
enable_language(ASM_MASM)


# Checks
if(NOT MSVC)
    message(FATAL_ERROR "Only microsoft compilers are supported right now")
endif()

# ================== USER SETTINGS ===================

# ================== COMPILER DEFINES ================


# =================== SETTINGS =======================
# Set C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")

# Enable multi-processor build
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP")

# Compiler settings
# Force unicode for all projects
add_definitions(-DUNICODE)
add_definitions(-D_UNICODE)

# Enable Testing
enable_testing()

# ================= INCLUDES/CMAKE =====================
# Include Dependencies
include(cmake/3rdparty/depends/zydis/zydis.cmake)

# Includes
include(cmake/3rdparty/ucm.cmake)

# ===================== MODULES ========================
# Sub-Modules
add_subdirectory(modules/BangNative)

# Main DLL
add_subdirectory(modules/DLL)

# Main Patcher EXE
add_subdirectory(modules/UHCPatcher)





# ============= TIMESTAMP FORCE TARGET =================
add_custom_target(ZERO_CHECK_FORCE ALL 
    COMMAND copy /b CMakeLists.txt +,,
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)
set_target_properties(ZERO_CHECK_FORCE PROPERTIES EXCLUDE_FROM_DEFAULT_BUILD 1)








