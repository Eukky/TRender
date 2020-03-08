#include "IndexBuffer.h"
#include "GraphicsAPI.h"
#include "Graphics/GLGraphics/GLIndexBuffer.h"

namespace TRender {
    namespace Graphics {
        std::shared_ptr<IndexBuffer> IndexBuffer::create(uint32_t* indices, uint32_t count) {
            switch(Graphics::GraphicsAPI::getAPI()) {
                case GraphicsAPI::GraphicsAPIList::None: {
                    TR_CORE_ASSERT(false, "Graphics API NONE is currently not supported");
                    return nullptr;
                }
                case GraphicsAPI::GraphicsAPIList::Opengl: {
                    return std::make_shared<GLIndexBuffer>(indices, count);
                    // return std::unique_ptr<GLIndexBuffer>(new GLIndexBuffer());
                }
                case GraphicsAPI::GraphicsAPIList::Valkun: {
                    TR_CORE_ASSERT(false, "Graphics API VALKUN is currently not supported");
                    return nullptr;
                }
            }
        }
    }
}
