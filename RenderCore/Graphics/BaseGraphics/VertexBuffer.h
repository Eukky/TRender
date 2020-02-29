#ifndef _TRENDER_GRAPHICS_VERTEXBUFFER_H_
#define _TRENDER_GRAPHICS_VERTEXBUFFER_H_

#include <memory>
#include "BufferLayout.h"

namespace TRender {
    namespace Graphics {
        class VertexBuffer {
        public:
            virtual ~VertexBuffer() = default;

            virtual void bind() const = 0;
            virtual void unbind() const = 0;

            virtual const BufferLayout& getLayout() const = 0;
            virtual void setLayout(const BufferLayout& layout) = 0;

            static std::shared_ptr<VertexBuffer> create(float* vertices, uint32_t size);
        };
    }
}

#endif //_TRENDER_GRAPHICS_VERTEXBUFFER_H_