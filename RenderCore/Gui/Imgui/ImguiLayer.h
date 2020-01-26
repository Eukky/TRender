#ifndef _TRENDER_GUI_IMGUILAYER_H_
#define _TRENDER_GUI_IMGUILAYER_H_

#include <imgui.h>
#include "ImguiOpenGLRender.h"
#include "ImguiGLFW.h"
#include "Core/CoreHead.h"
#include "Event/EventHead.h"

namespace TRender {
    namespace Gui {
        class ImguiLayer : public Core::Layer {
        public:
            ImguiLayer();
            ~ImguiLayer();

            virtual void onAttach();
            virtual void onDetach();

            virtual void onUpdate();
            virtual void onEvent(Event::Event& event); 

            void begin();
            void end();
        private:
            float m_Time = 0.0f;
        };
    }
}

#endif //_TRENDER_GUI_IMGUILAYER_H_
