#include "GLGraphicsAPI.h"
#include <GL/glew.h>
namespace TRender {
    namespace Graphics {

        GLGraphicsAPI::~GLGraphicsAPI() {

        }

        void GLGraphicsAPI::init() {
            glEnable(GL_BLEND);
            glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
            // glBlendFunc(GL_ONE, GL_ONE);
            glEnable(GL_DEPTH_TEST);
        }

        void GLGraphicsAPI::setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {
            glViewport(x, y, width, height);
        }

        void GLGraphicsAPI::setClearColor(const glm::vec4& color) {
            glClearColor(color.r, color.g, color.b, color.a);
        }

        void GLGraphicsAPI::clear() {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void GLGraphicsAPI::drawIndexed(const std::shared_ptr<VertexArray> &vertexArray) {
            glDrawElements(GL_TRIANGLES, vertexArray->getIndexBuffer()->getCount(), GL_UNSIGNED_INT, nullptr);
		    glBindTexture(GL_TEXTURE_2D, 0);
        }
    }
}