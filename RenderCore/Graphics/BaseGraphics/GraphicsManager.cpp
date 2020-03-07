#include "GraphicsManager.h"
#include "GraphicsAPI.h"
#include <GL/glew.h>

namespace TRender {
    namespace Graphics {

        std::unique_ptr<GraphicsAPI> GraphicsManager::s_GraphicsAPI = GraphicsAPI::create();

        void GraphicsManager::drawIndexed(const std::shared_ptr<VertexArray> &vertexArray) {
            s_GraphicsAPI->drawIndexed(vertexArray);
        }
    }
}