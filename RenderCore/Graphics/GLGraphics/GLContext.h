#ifndef _TRENDER_GRAPHICS_GLCONTEXT_H_
#define _TRENDER_GRAPHICS_GLCONTEXT_H_

#include "Graphics/BaseGraphics/BaseContext.h"
#include <GLFW/glfw3.h>

struct GLFWwindow;

namespace TRender {
    namespace Graphics {
        class GLContext : public BaseContext {
        public: 
            GLContext(GLFWwindow* windowHandle);

            virtual void Init() override;
            virtual void SwapBuffers() override;

        private:
            GLFWwindow* m_WindowHandle;
        };
    }
}

#endif //_TRENDER_GRAPHICS_GLCONTEXT_H_