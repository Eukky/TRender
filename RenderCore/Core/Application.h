#ifndef _TRENDER_CORE_APPLICATION_H_
#define _TRENDER_CORE_APPLICATION_H_

#include "Window.h"
#include "Event/EventHead.h"

namespace TRender {
    namespace Core {
        class Application {
        public:
            Application();
            virtual ~Application();
            void run();
            void onEvent(Event::Event& e);

        private:
            bool onWindowClose(Event::WindowCloseEvent& e);
            bool onWindowResize(Event::WindowResizeEvent& e);
        private:
            std::unique_ptr<Window> m_Window;
            bool m_Running = true;
        };

        Application* createApplication();
    }
}

#endif //_TRENDER_CORE_APPLICATION_H_