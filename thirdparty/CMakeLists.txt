

add_subdirectory(hooking-api)
add_subdirectory(spdlog)

set_target_properties(spdlog PROPERTIES POSITION_INDEPENDENT_CODE ON)
