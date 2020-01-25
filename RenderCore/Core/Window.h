#ifndef _TINYRENDER_CORE_WINDOW_H_
#define _TINYRENDER_CORE_WINDOW_H_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <functional>
#include "Event/Event.h"
#include "Event/EventDispatcher.h"

namespace TRender {
    namespace Core {
        class Window {
        public:
            Window(const char *title, int width, int height);
            ~Window() {}
            void clear() const;
            void update();
            bool closed() const;
            int getWidth() const;
            int getHeight() const;
            void setEventCallback(const std::function<void(Event::Event&)>& callback);
            void setVSync(bool enabled);
            bool isVSync();
            int getWindowCount();
            
            void createWindow();
            void* getWindow() const;
        private:
            bool initGLFW();
            bool initWindow();
            static void windowSizeCallback(GLFWwindow* window, int width, int height);
            static void windowCloseCallback(GLFWwindow* window);
            static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
            static void charCallback(GLFWwindow* window, unsigned int keycode);
            static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
            static void scrollCallback(GLFWwindow* window, double xOffset, double yOffset);
            static void cursorCallback(GLFWwindow* window, double xPos, double yPos);
        private:
            unsigned int m_GLFWWindowCount = 0;
            GLFWwindow *m_Window;

            struct WindowData {
                const char* title;
                unsigned int width, height;
                bool isVSync;

                std::function<void(Event::Event&)> EventCallback;
            };

            WindowData m_WindowData;
            

            
        };
    }
}

#endif // _TINYRENDER_CORE_WINDOW_H_
