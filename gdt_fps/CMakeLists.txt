
add_library(gdt_fps SHARED ./src/ascii.cpp ./src/hooker.cpp)

target_link_libraries(gdt_fps hook gdt_common glm freetype)

set_target_properties(gdt_fps PROPERTIES POSITION_INDEPENDENT_CODE ON)

set_target_properties(gdt_fps PROPERTIES CXX_STANDARD 17)
