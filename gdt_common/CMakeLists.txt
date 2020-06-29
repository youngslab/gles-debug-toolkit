

add_library(gdt_common STATIC ./src/init.cpp)

target_link_libraries(gdt_common PUBLIC spdlog)
