#include "BaseGraphics.h"
#include "GraphicsManager.h"

namespace TRender {
    namespace Graphics {

        std::unique_ptr<BaseGraphics::SceneData> BaseGraphics::s_SceneData = std::unique_ptr<BaseGraphics::SceneData>(new BaseGraphics::SceneData());


        void BaseGraphics::init() {
            GraphicsManager::init();
        }

        void BaseGraphics::Shutdown() {

        }

        void BaseGraphics::OnWindowResize(uint32_t width, uint32_t height) {
            GraphicsManager::setViewPort(0, 0, width, height);
        }

        GraphicsAPI::GraphicsAPIList BaseGraphics::getAPI() {
            return GraphicsAPI::getAPI();
        }

        void BaseGraphics::submit(const std::shared_ptr<BaseShader> &shader, 
                                  std::shared_ptr<VertexArray> &vertexArray, 
                                  const glm::mat4& transform) {
//            s_SceneData->viewProjectMatrix = glm::mat4(1.0);
            shader->bind();
            shader->setMat4("u_ViewProjection", s_SceneData->viewProjectMatrix);
            shader->setMat4("u_Transform", transform);
            vertexArray->bind();

            GraphicsManager::drawIndexed(vertexArray);

        }

        void BaseGraphics::BeginScene(Core::Camera& camera) {
            s_SceneData->viewProjectMatrix = camera.getViewProjectionMatrix();
        }
        void BaseGraphics::EndScene() {
            
        }


    }
}
