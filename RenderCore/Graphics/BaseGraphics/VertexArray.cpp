#include "VertexArray.h"
#include "GraphicsAPI.h"
#include "Graphics/GLGraphics/GLVertexArray.h"
#include "Common/CommonHead.h"
#include <memory>

namespace TRender {
    namespace Graphics {
        std::shared_ptr<VertexArray> VertexArray::creat() {
            switch(Graphics::GraphicsAPI::getAPI()) {
                case GraphicsAPI::GraphicsAPIList::None: {
                    TR_CORE_ASSERT(false, "Graphics API NONE is currently not supported");
                    return nullptr;
                }
                case GraphicsAPI::GraphicsAPIList::Opengl: {
                    return std::unique_ptr<GLVertexArray>(new GLVertexArray());
                }
                case GraphicsAPI::GraphicsAPIList::Valkun: {
                    TR_CORE_ASSERT(false, "Graphics API VALKUN is currently not supported");
                    return nullptr;
                }
            }
        }
    }   
}
