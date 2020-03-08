#include "GraphicsManager.h"
#include "GraphicsAPI.h"
#include <GL/glew.h>

namespace TRender {
    namespace Graphics {

        std::unique_ptr<GraphicsAPI> GraphicsManager::s_GraphicsAPI = GraphicsAPI::create();

        void GraphicsManager::init() {
            s_GraphicsAPI->init();
        }

        void GraphicsManager::setViewPort(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
            s_GraphicsAPI->setViewport(x, y, width, height);
        }

        void GraphicsManager::setClearColor(const glm::vec4& color) {
            s_GraphicsAPI->setClearColor(color);
        }

        void GraphicsManager::clear() {
            s_GraphicsAPI->clear();
        }

        void GraphicsManager::drawIndexed(const std::shared_ptr<VertexArray> &vertexArray) {
            s_GraphicsAPI->drawIndexed(vertexArray);
        }
    }
}