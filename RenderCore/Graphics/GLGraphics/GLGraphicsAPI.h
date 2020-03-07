#ifndef _TRENDER_GRAPHICS_GLGRAPHICSAPI_H_
#define _TRENDER_GRAPHICS_GLGRAPHICSAPI_H_

#include "Graphics/BaseGraphics/GraphicsAPI.h"
#include "Graphics/BaseGraphics/VertexArray.h"
namespace TRender {
    namespace Graphics {
        class GLGraphicsAPI : public GraphicsAPI{
        public:
            virtual void init() override;
            virtual void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;

            virtual void setClearColor(const glm::vec4& color) override;
            virtual void clear() override;

            virtual void drawIndexed(const std::shared_ptr<VertexArray> &vertexArray) override;
        };
    }
}

#endif //_TRENDER_GRAPHICS_GLGRAPHICSAPI_H_