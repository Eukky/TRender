project(TRender)

set(DIR_LIB_SRCS "./")
file (GLOB_RECURSE  SOURCES 
                    "${DIR_LIB_SRCS}/*.h"
					"${DIR_LIB_SRCS}/*.cpp"
					)
add_library (RenderCore ${SOURCES})

target_link_libraries(RenderCore PRIVATE glfw)
target_link_libraries(RenderCore PRIVATE libglew_static)
target_link_libraries(RenderCore PRIVATE glm)