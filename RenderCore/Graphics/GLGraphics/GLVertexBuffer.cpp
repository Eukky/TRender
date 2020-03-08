#include "GLVertexBuffer.h"
#include <GL/glew.h>

namespace TRender {
    namespace Graphics {
        GLVertexBuffer::GLVertexBuffer(float* vertices, uint32_t size){
            glGenBuffers(1, &m_RenderID);
            glBindBuffer(GL_ARRAY_BUFFER, m_RenderID);
            glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
        }

        GLVertexBuffer::~GLVertexBuffer() {
            glDeleteBuffers(1, &m_RenderID);
        }

        void GLVertexBuffer::bind() const {
            glBindBuffer(GL_ARRAY_BUFFER, m_RenderID);
        }

        void GLVertexBuffer::unbind() const {
            glBindBuffer(GL_ARRAY_BUFFER, 0);
        }

        const BufferLayout& GLVertexBuffer::getLayout() const {
            return m_Layout;
        }

        void GLVertexBuffer::setLayout(const BufferLayout& layout) {
            m_Layout = layout;
        }
    }
}