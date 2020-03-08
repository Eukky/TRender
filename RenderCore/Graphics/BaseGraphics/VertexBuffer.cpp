#include "VertexBuffer.h"
#include "BaseGraphics.h"
#include "Graphics/GLGraphics/GLVertexBuffer.h"

namespace TRender {
    namespace Graphics {
        std::shared_ptr<VertexBuffer> VertexBuffer::create(float* vertices, uint32_t size) {
            switch (Graphics::GraphicsAPI::getAPI()) {
                case Graphics::GraphicsAPI::GraphicsAPIList::None: {
                    TR_CORE_ASSERT(false, "Graphics API None is currently not supported!");
                    return nullptr;
                }
                case Graphics::GraphicsAPI::GraphicsAPIList::Opengl: {
                    return std::make_shared<GLVertexBuffer>(vertices, size);
                    // return std::shared_ptr<GLVertexBuffer>(new GLVertexBuffer(vertices, size));
                }
                case Graphics::GraphicsAPI::GraphicsAPIList::Valkun: {
                    TR_CORE_ASSERT(false, "Graphics API Valkun is currently not supported!");
                    return nullptr;
                }

                TR_CORE_ASSERT(false, "Unknown Graphics API!");
                return nullptr;
            }
        }
    }
}