#include "BaseGraphics.h"
#include "GraphicsManager.h"

namespace TRender {
    namespace Graphics {

        std::unique_ptr<BaseGraphics::SceneData> BaseGraphics::s_SceneData = std::unique_ptr<BaseGraphics::SceneData>(new BaseGraphics::SceneData());

        GraphicsAPI::GraphicsAPIList BaseGraphics::getAPI() {
            return GraphicsAPI::getAPI();
        }

        void BaseGraphics::submit(const std::shared_ptr<BaseShader> &shader, 
                                  std::shared_ptr<VertexArray> &vertexArray, 
                                  const glm::mat4& transform) {
            shader->bind();
            shader->setMat4("u_ViewProjection", s_SceneData->viewProjectMatrix);
            shader->setMat4("u_Transform", transform);
            vertexArray->bind();

            GraphicsManager::drawIndexed(vertexArray);

        }
    }
}
