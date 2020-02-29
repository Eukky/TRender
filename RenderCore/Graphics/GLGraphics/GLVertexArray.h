#ifndef _TRENDER_GRAPHICS_GLVERTEXARRAY_H_
#define _TRENDER_GRAPHICS_GLVERTEXARRAY_H_

#include "Graphics/BaseGraphics/VertexArray.h"

namespace TRender {
    namespace Graphics {
        class GLVertexArray : public VertexArray{
        public:
            GLVertexArray();
            virtual ~GLVertexArray();

            virtual void bind() const override;
            virtual void unbind() const override;

            virtual void addVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) override;
            virtual void setIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) override;

            virtual const std::vector<std::shared_ptr<VertexBuffer>>& getVertexBuffer() const override;
            virtual const std::shared_ptr<IndexBuffer>& getIndexBuffer() const override;

        private:
            uint32_t m_RenderID;
            uint32_t m_VertexBufferIndex = 0;
            std::vector<std::shared_ptr<VertexBuffer>> m_VertexBuffers;
            std::shared_ptr<IndexBuffer> m_IndexBuffer;
        };
    }
}

#endif //_TRENDER_GRAPHICS_GLVERTEXARRAY_H_