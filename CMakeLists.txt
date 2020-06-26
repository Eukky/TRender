cmake_minimum_required(VERSION 3.1)
project(TRender)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -std=c++14 -std=c++17")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories("${PROJECT_SOURCE_DIR}/RenderCore")
include_directories("${PROJECT_SOURCE_DIR}/include")

if(APPLE)
    set(CMAKE_MACOSX_RPATH 1)
endif(APPLE)

add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)

add_definitions(-DGLEW_STATIC)
add_subdirectory(lib/glew EXCLUDE_FROM_ALL)

add_subdirectory(lib/spdlog EXCLUDE_FROM_ALL)

add_subdirectory(lib/imgui EXCLUDE_FROM_ALL)

add_subdirectory(Game)
add_subdirectory(RenderCore)