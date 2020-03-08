#ifndef _TRENDER_GRAPHICS_GLINDEXBUFFER_H_
#define _TRENDER_GRAPHICS_GLINDEXBUFFER_H_

#include "Graphics/BaseGraphics/IndexBuffer.h"

namespace TRender {
    namespace Graphics {
        class GLIndexBuffer : public IndexBuffer {
        public:
            GLIndexBuffer(uint32_t* indices, uint32_t count);
            virtual ~GLIndexBuffer();

            virtual void bind() const override;
            virtual void unbind() const override;

            virtual uint32_t getCount() const override;
        private:
            uint32_t m_RenderID;
            uint32_t m_Count;
        };
    }
}

#endif //_TRENDER_GRAPHICS_GLINDEXBUFFER_H_