#ifndef _TRENDER_CORE_APPLICATION_H_
#define _TRENDER_CORE_APPLICATION_H_

namespace TRender {
    namespace Core {
        class Application {
        public:
            Application();
            virtual ~Application();
            void run();
        };

        Application* createApplication();
    }
}

#endif //_TRENDER_CORE_APPLICATION_H_