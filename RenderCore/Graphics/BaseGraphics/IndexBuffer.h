#ifndef _TRENDER_GRAPHICS_INDEXBUFFER_H_
#define _TRENDER_GRAPHICS_INDEXBUFFER_H_

#include <memory>
#include "BufferLayout.h"

namespace TRender {
    namespace Graphics {
        class IndexBuffer {
        public:
            virtual ~IndexBuffer() = default;

            virtual void bind() const = 0;
            virtual void unbind() const = 0;

            virtual uint32_t getCount() const = 0;

            static std::shared_ptr<IndexBuffer> create(uint32_t* indices, uint32_t count);

        };
    }   
}



#endif //_TRENDER_GRAPHICS_INDEXBUFFER_H_