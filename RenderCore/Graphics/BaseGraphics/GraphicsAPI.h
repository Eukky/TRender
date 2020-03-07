#ifndef _TRENDER_GRAPHICS_GRAPHICSAPI_H_
#define _TRENDER_GRAPHICS_GRAPHICSAPI_H_

#include <memory>
#include <glm/glm.hpp>
#include "Graphics/BaseGraphics/VertexArray.h"
namespace TRender {
    namespace Graphics {
        class GraphicsAPI {
        public:
            enum class GraphicsAPIList {
                None = 0,
                Opengl = 1,
                Valkun = 2
            };

        public:
            virtual void init() = 0;
            virtual void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) = 0;
            virtual void setClearColor(const glm::vec4& color) = 0;
            virtual void clear() = 0;

            virtual void drawIndexed(const std::shared_ptr<VertexArray> &vertexArray) = 0;
            static GraphicsAPIList getAPI();
            static std::unique_ptr<GraphicsAPI> create();

        private:
            static GraphicsAPIList s_API;
        };
    }
}

#endif //_TRENDER_GRAPHICS_GRAPHICSAPI_H_