#include "Window.h"
#include "Common/Tlog.h"
#include "Event/EventHead.h"
#include <iostream>

namespace TRender {
    namespace Core {

        static void GLFWErrorCallback(int error, const char* description)
        {
            TR_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
        }

        Window::Window(const char *title, int width, int height){
            m_WindowData.title = title;
            m_WindowData.width = width;
            m_WindowData.height = height;
            
        }

        void Window::createWindow() {
            if(m_GLFWWindowCount == 0) {
                if(!initGLFW()) {
                    TR_CORE_ERROR("Failed to init GLFW");
                }
            }
  
            if(!initWindow()) {
                TR_CORE_ERROR("Failed to init Window");
            }
        }

        bool Window::initWindow() {
     
            TR_CORE_INFO("Creating Window {0}, width: {1}, height: {2}", m_WindowData.title, m_WindowData.width, m_WindowData.height);
            m_Window = glfwCreateWindow(m_WindowData.width, m_WindowData.height, m_WindowData.title, NULL, NULL);
            m_GLFWWindowCount++;
            glfwMakeContextCurrent(m_Window);
            glfwSetWindowUserPointer(m_Window, &m_WindowData);
            setVSync(true);

            glfwSetWindowSizeCallback(m_Window, windowSizeCallback);
            glfwSetWindowCloseCallback(m_Window, windowCloseCallback);
            glfwSetKeyCallback(m_Window, keyCallback);
            glfwSetCharCallback(m_Window, charCallback);
            glfwSetMouseButtonCallback(m_Window, mouseButtonCallback);
            glfwSetScrollCallback(m_Window, scrollCallback);
            glfwSetCursorPosCallback(m_Window, cursorCallback);
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

        void Window::setEventCallback(const std::function<void(Event::Event&)>& callback) {
            m_WindowData.EventCallback = callback;
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

        void Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch (action) {
                case GLFW_PRESS: {
                    Event::KeyPressedEvent event(key, 0);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    Event::KeyReleasedEvent event(key);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_REPEAT: {
                    Event::KeyPressedEvent event(key, 1);
                    data.EventCallback(event);
                    break;
                }
                default:
                    break;
            }
        }

        void Window::charCallback(GLFWwindow* window, unsigned int keycode) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            Event::KeyTypedEvent event(keycode);
            data.EventCallback(event);
        }

        void Window::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch (action) {
                case GLFW_PRESS: {
                    Event::MouseButtonPressedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
                case GLFW_RELEASE: {
                    Event::MouseButtonReleasedEvent event(button);
                    data.EventCallback(event);
                    break;
                }
                default:
                    break;
            }
        }

        void Window::scrollCallback(GLFWwindow* window, double xOffset, double yOffset) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            Event::MouseScrolledEvent event((float)xOffset, (float)yOffset);
            data.EventCallback(event);
        }

        void Window::cursorCallback(GLFWwindow* window, double xPos, double yPos) {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            Event::MouseMovedEvent event((float)xPos, (float)yPos);
            data.EventCallback(event);
        }


    }
}