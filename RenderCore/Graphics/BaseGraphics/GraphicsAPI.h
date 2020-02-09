#ifndef _TRENDER_GRAPHICS_GRAPHICSAPI_H_
#define _TRENDER_GRAPHICS_GRAPHICSAPI_H_

namespace TRender {
    namespace Graphics {
        class GraphicsAPI {
        public:
            enum class GraphicsAPIList {
                NONE = 0,
                OPENGL = 1,
                VALKUN = 2
            };

        public:
            static GraphicsAPIList getAPI();

        private:
            static GraphicsAPIList m_API;
        };
    }
}

#endif //_TRENDER_GRAPHICS_GRAPHICSAPI_H_