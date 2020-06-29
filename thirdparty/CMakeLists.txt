

add_subdirectory(hooking-api)
add_subdirectory(spdlog)
add_subdirectory(glm)
add_subdirectory(freetype2)

set_target_properties(spdlog PROPERTIES POSITION_INDEPENDENT_CODE ON)
set_target_properties(freetype PROPERTIES POSITION_INDEPENDENT_CODE ON)
