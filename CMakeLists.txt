
cmake_minimum_required(VERSION 3.12)

project(gles_debug_toolkit)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(thirdparty)
add_subdirectory(gdt_common)
add_subdirectory(gdt_logger)
add_subdirectory(gdt_info)
