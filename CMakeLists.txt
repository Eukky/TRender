cmake_minimum_required(VERSION 3.1)
project(TRender)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories("${PROJECT_SOURCE_DIR}/RenderCore")

if(APPLE)
    set(CMAKE_MACOSX_RPATH 1)
endif(APPLE)

option(GLFW_BUILD_DOCS OFF)
option(GLFW_BUILD_EXAMPLES OFF)
option(GLFW_BUILD_TESTS OFF)
add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)

add_definitions(-DGLEW_STATIC)
add_subdirectory(lib/glew EXCLUDE_FROM_ALL)

add_subdirectory(lib/glm EXCLUDE_FROM_ALL)

add_subdirectory(Game)
add_subdirectory(RenderCore)