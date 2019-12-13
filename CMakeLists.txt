cmake_minimum_required(VERSION 3.1)
project(TRender)

include_directories("${PROJECT_SOURCE_DIR}/RenderCore")

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)

add_definitions(-DGLEW_STATIC)
add_subdirectory(lib/glew EXCLUDE_FROM_ALL)

add_subdirectory(lib/glm EXCLUDE_FROM_ALL)

add_subdirectory(Sample)
add_subdirectory(RenderCore)