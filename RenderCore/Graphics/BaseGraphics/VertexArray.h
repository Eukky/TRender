#ifndef _TRENDER_GRAPHICS_VERTEXARRAY_H_
#define _TRENDER_GRAPHICS_VERTEXARRAY_H_

#include <memory>
#include <vector>
#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace TRender {
    namespace Graphics {
        class VertexArray {
        public:
            virtual ~VertexArray() {}

            virtual void bind() const = 0;
            virtual void unbind() const = 0;

            virtual void addVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) = 0;
            virtual void setIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) = 0;

            virtual const std::vector<std::shared_ptr<VertexBuffer>>& getVertexBuffer() const = 0;
            virtual const std::shared_ptr<IndexBuffer>& getIndexBuffer() const = 0;

            static std::shared_ptr<VertexArray> create();
        };
    }
}

#endif //_TRENDER_GRAPHICS_VERTEXARRAY_H_