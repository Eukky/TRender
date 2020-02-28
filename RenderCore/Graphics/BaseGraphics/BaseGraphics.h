#ifndef _TRENDER_GRAPHICS_BASEGRAPHICS_H_
#define _TRENDER_GRAPHICS_BASEGRAPHICS_H_

#include "GraphicsAPI.h"
#include "BaseShader.h"
#include "VertexArray.h"

namespace TRender {
    namespace Graphics {
        class BaseGraphics {
        public:
            static void submit(const std::shared_ptr<BaseShader> &shader, 
                               std::shared_ptr<VertexArray> &vertexArray, 
                               const glm::mat4& transform = glm::mat4(1.0f));

            static GraphicsAPI::GraphicsAPIList getAPI();
        private:
        };
    }
}

#endif //_TRENDER_GRAPHICS_BASEGRAPHICS_H_