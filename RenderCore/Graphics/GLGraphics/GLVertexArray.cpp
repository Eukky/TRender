#include "GLVertexArray.h"
#include "Common/CommonHead.h"
#include <GL/glew.h>
namespace TRender {
    namespace Graphics {
        GLVertexArray::GLVertexArray() {
            glCreateVertexArrays(1, &m_RenderID);
        }

        GLVertexArray::~GLVertexArray() {
            glDeleteVertexArrays(1, &m_RenderID);
        }

        void GLVertexArray::bind() const {
            glBindVertexArray(m_RenderID);
        }

        void GLVertexArray::unbind() const {
            glBindVertexArray(0);
        }

        void GLVertexArray::addVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) {
            TR_CORE_ASSERT(vertexBuffer->getLayout().getElements().size(), "Vertex Buffer has no layout");
        }

        void GLVertexArray::setIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) {

        }


    }
}