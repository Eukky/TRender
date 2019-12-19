#include "Window.h"

namespace TRender {
    namespace Graphics {
        Window::Window(const char *title, int width, int height){
            if(!init()){
                std::cout << "Failed to init Window" << std::endl;
            }
            m_Title = title;
            m_Width = width;
            m_Height = height;
            m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
            glfwMakeContextCurrent(m_Window);
        }
        void Window::clear() const {
            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);
        }
        void Window::update() {
            glfwSwapBuffers(m_Window);
            glfwPollEvents();
        }
        bool Window::closed() const {
            return glfwWindowShouldClose(m_Window);
        }
        bool Window::init() {
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        #ifdef __APPLE__
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        #endif // __APPLE__
            return true;
        }

    }
}