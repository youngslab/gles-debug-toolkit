

add_library(gdt_logger SHARED ./src/egl_logger ./src/gles_logger)

target_link_libraries(gdt_logger hook gdt_common)

set_target_properties(gdt_logger PROPERTIES CXX_STANDARD 17)
