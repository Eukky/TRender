#include "GLContext.h"
#include "Common/CommonHead.h"

namespace TRender {
    namespace Graphics {
        GLContext::GLContext(GLFWwindow* windowHandle) : m_WindowHandle(windowHandle) {
            if(!m_WindowHandle) {
                TR_CORE_ERROR("GLContext::Window is not handled!");
            }
        }

        void GLContext::Init() {
            glfwMakeContextCurrent(m_WindowHandle);
            
        }

        void GLContext::SwapBuffers() {

        }
    }
}