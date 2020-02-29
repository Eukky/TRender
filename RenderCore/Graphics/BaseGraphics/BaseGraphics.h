#ifndef _TRENDER_GRAPHICS_BASEGRAPHICS_H_
#define _TRENDER_GRAPHICS_BASEGRAPHICS_H_

#include "GraphicsAPI.h"
#include "BaseShader.h"
#include "VertexArray.h"
#include <glm/glm.hpp>

namespace TRender {
    namespace Graphics {
        class BaseGraphics {
        public:
            static void submit(const std::shared_ptr<BaseShader> &shader, 
                               std::shared_ptr<VertexArray> &vertexArray, 
                               const glm::mat4& transform = glm::mat4(1.0f));

            static GraphicsAPI::GraphicsAPIList getAPI();
        private:
            struct SceneData {
                glm::mat4 viewProjectMatrix;
            };

            static std::unique_ptr<SceneData> s_SceneData;
        };
    }
}

#endif //_TRENDER_GRAPHICS_BASEGRAPHICS_H_