#ifndef _TRENDER_GRAPHICS_BASEGRAPHICS_H_
#define _TRENDER_GRAPHICS_BASEGRAPHICS_H_

#include "GraphicsAPI.h"

namespace TRender {
    namespace Graphics {
        class BaseGraphics {
        public:
            static GraphicsAPI::GraphicsAPIList getAPI();
        private:
        };
    }
}

#endif //_TRENDER_GRAPHICS_BASEGRAPHICS_H_