#include "GLVertexArray.h"
#include "Common/CommonHead.h"
#include <GL/glew.h>
namespace TRender {
    namespace Graphics {

        static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
        {
            switch (type)
            {
                case ShaderDataType::Float:    return GL_FLOAT;
                case ShaderDataType::Float2:   return GL_FLOAT;
                case ShaderDataType::Float3:   return GL_FLOAT;
                case ShaderDataType::Float4:   return GL_FLOAT;
                case ShaderDataType::Mat3:     return GL_FLOAT;
                case ShaderDataType::Mat4:     return GL_FLOAT;
                case ShaderDataType::Int:      return GL_INT;
                case ShaderDataType::Int2:     return GL_INT;
                case ShaderDataType::Int3:     return GL_INT;
                case ShaderDataType::Int4:     return GL_INT;
                case ShaderDataType::Bool:     return GL_BOOL;
            }

            TR_CORE_ASSERT(false, "Unknown ShaderDataType!");
            return 0;
        }

        GLVertexArray::GLVertexArray() {
            glewInit();
            glGenVertexArrays(1, &m_RenderID);
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
            glBindVertexArray(m_RenderID);
            vertexBuffer->bind();

            const auto& layout = vertexBuffer->getLayout();
            for(const auto& element : layout) {
                glEnableVertexAttribArray(m_VertexBufferIndex);
			    glVertexAttribPointer(m_VertexBufferIndex,
                                      element.getComponentCount(),
                                      ShaderDataTypeToOpenGLBaseType(element.type),
                                      element.normalized ? GL_TRUE : GL_FALSE,
                                      layout.getStride(),
                                      (const void*)element.offset);
			    m_VertexBufferIndex++;
            }

            m_VertexBuffers.push_back(vertexBuffer);
        }

        void GLVertexArray::setIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) {

        }

        const std::vector<std::shared_ptr<VertexBuffer>>& GLVertexArray::getVertexBuffer() const {
            return m_VertexBuffers;
        }

        const std::shared_ptr<IndexBuffer>& GLVertexArray::getIndexBuffer() const {
            return m_IndexBuffer;
        }

    }
}