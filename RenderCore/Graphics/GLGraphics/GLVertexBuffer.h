#ifndef _TRENDER_GRAPHICS_GLVERTEXBUFFER_H_
#define _TRENDER_GRAPHICS_GLVERTEXBUFFER_H_

#include "Graphics/BaseGraphics/VertexBuffer.h"

namespace TRender {
    namespace Graphics {
        class GLVertexBuffer : public VertexBuffer {
        public:
            GLVertexBuffer(float* vertices, uint32_t size);
            ~GLVertexBuffer();

            virtual void bind() const override;
            virtual void unbind() const override;

            virtual const BufferLayout& getLayout() const override;
            virtual void setLayout(const BufferLayout& layout) override;
        };
    }
}

#endif //_TRENDER_GRAPHICS_GLVERTEXBUFFER_H_