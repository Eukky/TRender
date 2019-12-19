project(TRender)

add_executable(Game GameApp.cpp)

target_link_libraries(Game PRIVATE glfw)
target_link_libraries(Game PRIVATE libglew_static)
target_link_libraries(Game PRIVATE glm)
target_link_libraries(Game PRIVATE RenderCore)
