#ifndef _TINYRENDER_GRAPHICS_WINDOW_
#define _TINYRENDER_GRAPHICS_WINDOW_

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace TRender {
    namespace Graphics {
        class Window {
        public:
            Window(const char *title, int width, int height);
            // ~Window();
            void clear() const;
            void update();
            bool closed() const;
            inline int getWidth() const { return m_Width; }
            inline int getHeight() const { return m_Height; }
        private:
            bool init();
        private:
            const char *m_Title;
            int m_Width, m_Height;
            GLFWwindow *m_Window;
            bool m_Closed;
        };
    }
}

#endif // _TINYRENDER_GRAPHICS_WINDOW_
