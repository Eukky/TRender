#ifndef _TRENDER_GRAPHICS_BASECONTEXT_H_
#define _TRENDER_GRAPHICS_BASECONTEXT_H_

#include <memory>

namespace TRender {
    namespace Graphics {
        class BaseContext {
        public:

            virtual void Init() = 0;
            virtual void SwapBuffers() = 0;

            static std::unique_ptr<BaseContext> CreatContext(void* window);
        };
    }
}

#endif //_TRENDER_GRAPHICS_BASECONTEXT_H_