get_filename_component(THIRD_PARTY_DIR ${CMAKE_CURRENT_SOURCE_DIR} DIRECTORY)
set(NUKLEAR_SRC_DIR ${THIRD_PARTY_DIR}/nuklear)

list(APPEND NUKLEAR_PUBLIC_HEADERS
        "${NUKLEAR_SRC_DIR}/nuklear.h"
        )

list(APPEND NUKLEAR_PRIVATE_HEADERS
        "${NUKLEAR_SRC_DIR}/src/nuklear.h"
        "${NUKLEAR_SRC_DIR}/src/nuklear_internal.h"

        )

    list(APPEND NUKLEAR_SOURCES
        "${NUKLEAR_SRC_DIR}/src/nuklear_buffer.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_button.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_chart.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_color_picker.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_color.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_combo.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_context.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_contextual.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_draw.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_edit.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_font.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_group.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_image.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_input.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_layout.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_list_view.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_math.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_menu.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_page_element.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_panel.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_pool.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_popup.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_progress.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_property.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_scrollbar.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_selectable.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_slider.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_string.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_style.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_table.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_text_editor.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_text.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_toggle.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_tooltip.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_tree.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_utf8.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_util.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_vertex.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_widget.c"
        "${NUKLEAR_SRC_DIR}/src/nuklear_window.c"
        ${NUKLEAR_PUBLIC_HEADERS}
        ${NUKLEAR_PRIVATE_HEADERS}
        )

list(APPEND NUKLEAR_PUBLIC_INCLUDE_DIRS
        ${NUKLEAR_SRC_DIR}
        )

list(APPEND NUKLEAR_PUBLIC_LIBRARIES)

set(NAME nuklear)
add_library(${NAME} STATIC ${NUKLEAR_SOURCES})
target_link_libraries(${NAME} PUBLIC ${NUKLEAR_PUBLIC_LIBRARIES})
target_include_directories(${NAME}
        PUBLIC  ${NUKLEAR_PUBLIC_INCLUDE_DIRS}
        PRIVATE ${NUKLEAR_PRIVATE_INCLUDE_DIRS}
        )