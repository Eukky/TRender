#include "GLIndexBuffer.h"
#include <GL/glew.h>
namespace TRender {
    namespace Graphics {
        GLIndexBuffer::GLIndexBuffer(uint32_t* indices, uint32_t count): m_Count(count){
            glGenBuffers(1, &m_RenderID);
            glBindBuffer(GL_ARRAY_BUFFER, m_RenderID);
            glBufferData(GL_ARRAY_BUFFER, count * sizeof(uint32_t), indices, GL_STATIC_DRAW);
        }

        GLIndexBuffer::~GLIndexBuffer() {

        }

        void GLIndexBuffer::bind() const {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RenderID);
        }

        void GLIndexBuffer::unbind() const {

        }

        uint32_t GLIndexBuffer::getCount() const {
            return m_Count;
        }
    }
}