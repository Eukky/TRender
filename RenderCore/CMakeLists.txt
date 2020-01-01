project(TRender)

set(DIR_LIB_GRAPHICS "./Graphics")
set(DIR_LIB_MATHS "./Maths")
set(DIR_LIB_COMMON "./Common")
set(DIR_LIB_CORE "./Core")

include_directories(DIR_LIB_GRAPHICS)
include_directories(DIR_LIB_MATHS)
include_directories(DIR_LIB_COMMON)
include_directories(DIR_LIB_CORE)

set(DIR_LIB_SRCS 
		${DIR_LIB_GRAPHICS},
		${DIR_LIB_MATHS},
		${DIR_LIB_COMMON},
		${DIR_LIB_CORE}
		)
		
file (GLOB_RECURSE  DIR_LIB_SRCS *.cpp *.cc *.c *.h *.hpp)
add_library (RenderCore ${DIR_LIB_SRCS})

target_link_libraries(RenderCore PRIVATE glfw)
target_link_libraries(RenderCore PRIVATE libglew_static)
target_link_libraries(RenderCore PRIVATE glm)
target_link_libraries(RenderCore PRIVATE spdlog)