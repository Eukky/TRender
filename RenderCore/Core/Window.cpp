#include "Window.h"
#include "Common/Tlog.h"
#include "Event/EventHead.h"
#include <iostream>

namespace TRender {
    namespace Graphics {

        static void GLFWErrorCallback(int error, const char* description)
        {
            TR_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
        }

        Window::Window(const char *title, int width, int height){
            if(m_GLFWWindowCount == 0) {
                if(!initGLFW()) {
                    TR_CORE_ERROR("Failed to init GLFW");
                }
            }
  
            if(!initWindow(title, width, height)) {
                TR_CORE_ERROR("Failed to init Window");
            }
        }

        bool Window::initWindow(const char *title, int width, int height) {
            m_WindowData.title = title;
            m_WindowData.width = width;
            m_WindowData.height = height;
            TR_CORE_INFO("Creating Window {0}, width: {1}, height: {2}", title, width, height);
            m_Window = glfwCreateWindow(width, height, title, NULL, NULL);
            m_GLFWWindowCount++;
            glfwMakeContextCurrent(m_Window);
            glfwSetWindowUserPointer(m_Window, &m_WindowData);
            setVSync(true);

            glfwSetWindowSizeCallback(m_Window, windowSizeCallback);
            glfwSetWindowCloseCallback(m_Window, windowCloseCallback);
            return true;
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
        bool Window::initGLFW() {
            glfwInit();
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        #ifdef __APPLE__
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        #endif // __APPLE__
            return true;
        }

        int Window::getWidth() const { 
            return m_WindowData.width; 
        }
        int Window::getHeight() const { 
            return m_WindowData.height; 
        }

        void Window::setVSync(bool enabled) {
            if(enabled) {
                glfwSwapInterval(1);
            } else {
                glfwSwapInterval(0);
            }

            m_WindowData.isVSync = enabled;
        }

        bool Window::isVSync() {
            return m_WindowData.isVSync;
        }

        int Window::getWindowCount() {
            return m_GLFWWindowCount;
        }

        void Window::windowSizeCallback(GLFWwindow* window, int width, int height) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.width = width;
			data.height = height;

			Event::WindowResizeEvent event(width, height);
			data.EventCallback(event);
        }

        void Window::windowCloseCallback(GLFWwindow* window) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            
            Event::WindowCloseEvent event;
            data.EventCallback(event);
        }



    }
}