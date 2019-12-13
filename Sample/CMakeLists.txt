project(TRender)

add_executable(main main.cpp)

target_link_libraries(main PRIVATE glfw)
target_link_libraries(main PRIVATE libglew_static)
target_link_libraries(main PRIVATE glm)
target_link_libraries(main PRIVATE RenderCore)
