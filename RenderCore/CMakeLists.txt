project(TRender)

add_library(RenderCore Graphics/window.cpp)

target_link_libraries(RenderCore PRIVATE glfw)
target_link_libraries(RenderCore PRIVATE libglew_static)
target_link_libraries(RenderCore PRIVATE glm)