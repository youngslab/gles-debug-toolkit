

add_library(gdt_common SHARED ./src/init.cpp)

target_link_libraries(gdt_common PUBLIC spdlog)
