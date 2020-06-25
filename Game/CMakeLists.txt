project(TRender)

aux_source_directory(. DIR_SRCS)
file (GLOB_RECURSE  DIR_SRCS *.cpp *.cc *.c *.h *.hpp)
add_executable(Game ${DIR_SRCS})

target_link_libraries(Game PRIVATE glfw)
target_link_libraries(Game PRIVATE libglew_static)
target_link_libraries(Game PRIVATE spdlog)
target_link_libraries(Game PRIVATE imgui)
target_link_libraries(Game PRIVATE RenderCore)
