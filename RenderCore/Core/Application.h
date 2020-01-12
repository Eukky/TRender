#ifndef _TRENDER_CORE_APPLICATION_H_
#define _TRENDER_CORE_APPLICATION_H_

#include "Window.h"

namespace TRender {
    namespace Core {
        class Application {
        public:
            Application();
            virtual ~Application();
            void run();
        private:
            std::unique_ptr<Window> m_Window;
            bool m_Running = true;
        };

        Application* createApplication();
    }
}

#endif //_TRENDER_CORE_APPLICATION_H_