#include "BaseContext.h" 
#include "BaseGraphics.h"
#include "Common/CommonHead.h"
#include "Graphics/GLGraphics/GLContext.h"

namespace TRender {
    namespace Graphics {
        std::unique_ptr<BaseContext> BaseContext::CreatContext(void* window) {
            switch(BaseGraphics::getAPI()) {
                case GraphicsAPI::GraphicsAPIList::None: {
                    TR_CORE_ASSERT(false, "RendererAPI::None! Please choose a kind of Render API"); 
                    return nullptr;
                }
                case GraphicsAPI::GraphicsAPIList::Opengl: {
                    return std::unique_ptr<GLContext>(new GLContext(static_cast<GLFWwindow*>(window)));
                }
                case GraphicsAPI::GraphicsAPIList::Valkun: {
                    TR_CORE_ASSERT(false, "RendererAPI::VALKUN is not supported currently"); 
                    return nullptr;
                }
            }
            return nullptr;
        }
    }
}