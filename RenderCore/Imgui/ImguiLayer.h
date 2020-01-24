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

            virtual void onAttach();
            virtual void onDetach();

            void begin();
            void end();
        private:
            float m_Time = 0.0f;
        };
    }
}

#endif //_TRENDER_IMGUI_IMGUILAYER_H_
