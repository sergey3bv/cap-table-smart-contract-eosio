cmake_minimum_required(VERSION 3.5)

include(ExternalProject)
# if no cdt root is given use default path
if(CDT_ROOT STREQUAL "" OR NOT CDT_ROOT)
   find_package(cdt)
endif()

ExternalProject_Add(
   cap_table_project
   SOURCE_DIR ${CMAKE_SOURCE_DIR}/src
   BINARY_DIR ${CMAKE_BINARY_DIR}/cap_table
   CMAKE_ARGS
       -DCMAKE_TOOLCHAIN_FILE=${CDT_ROOT}/lib/cmake/cdt/CDTWasmToolchain.cmake
       -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
   UPDATE_COMMAND ""
   PATCH_COMMAND ""
   TEST_COMMAND ""
   INSTALL_COMMAND ""
   BUILD_ALWAYS 1
)
