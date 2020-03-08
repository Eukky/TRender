#ifndef _TRENDER_GRAPHICS_GRAPHICSMANAGER_H_
#define _TRENDER_GRAPHICS_GRAPHICSMANAGER_H_

#include <glm/glm.hpp>
#include <memory>
#include "VertexArray.h"
#include "GraphicsAPI.h"
#include "Common/CommonHead.h"

namespace TRender {
    namespace Graphics {
        class GraphicsManager {
        public:
            static void init();
            static void setViewPort(uint32_t x, uint32_t y, uint32_t width, uint32_t height);
            static void setClearColor(const glm::vec4& color);
            static void clear();
            static void drawIndexed(const std::shared_ptr<VertexArray>& vertexArray);
        private:
            static std::unique_ptr<GraphicsAPI> s_GraphicsAPI;
        };
    }
}

#endif //_TRENDER_GRAPHICS_GRAPHICSMANAGER_H_