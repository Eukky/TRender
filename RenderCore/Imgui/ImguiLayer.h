#ifndef _TRENDER_IMGUI_IMGUILAYER_H_
#define _TRENDER_IMGUI_IMGUILAYER_H_

#include <imgui.h>
#include "Core/Layer.h"

namespace TRender {
    namespace Imgui {
        class ImguiLayer : public Core::Layer {
        public:
            ImguiLayer() {}
            ~ImguiLayer() {}
        };
    }
}

#endif //_TRENDER_IMGUI_IMGUILAYER_H_
