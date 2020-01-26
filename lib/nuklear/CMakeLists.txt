get_filename_component(THIRD_PARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
set(NUKLEAR_SRC_DIR ${THIRD_PARTY_DIR}/nuklear)

list(APPEND NUKLEAR_PUBLIC_HEADERS
        "${NUKLEAR_SRC_DIR}/nuklear.h"
        )

list(APPEND NUKLEAR_PRIVATE_HEADERS
        "${NUKLEAR_SRC_DIR}/nuklear.h"
        )

aux_source_directory("${NUKLEAR_SRC_DIR}/src" NUKLEAR_DIR_SRCS)

set(NAME nuklear)

add_library(${NAME} STATIC ${NUKLEAR_DIR_SRCS})
target_include_directories(${NAME}
        PRIVATE ${NUKLEAR_PRIVATE_HEADERS}
        )