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

            TR_CORE_INFO("OpenGL Info:");
            TR_CORE_INFO("Vendor: {0}", glGetString(GL_VENDOR));
            TR_CORE_INFO("Renderer: {0}", glGetString(GL_RENDERER));
            TR_CORE_INFO("Version: {0}", glGetString(GL_VERSION));
            
        }

        void GLContext::SwapBuffers() {
            glfwSwapBuffers(m_WindowHandle);
        }
    }
}