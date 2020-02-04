#ifndef _TRENDER_CORE_APPLICATION_H_
#define _TRENDER_CORE_APPLICATION_H_

#include <memory>
#include "Window.h"
#include "LayerStack.h"
#include "Event/EventHead.h"
#include "Imgui/ImguiLayer.h"

namespace TRender {
    namespace Core {
        class Application {
        public:
            Application();
            virtual ~Application();
            void run();
            void onEvent(Event::Event& e);

            void pushLayer(Layer* layer);
            void pushOverlay(Layer* overlay);
            void popLayer(Layer* layer);
            void popOverlay(Layer* overlay);

            static Application& getInstance();
            Window& getWindow();

        private:
            bool onWindowClose(Event::WindowCloseEvent& e);
            bool onWindowResize(Event::WindowResizeEvent& e);
        private:
            std::unique_ptr<Window> m_Window;
            LayerStack m_LayerStack;
            Imgui::ImguiLayer* m_ImguiLayer;
            bool m_Running = true;
            static Application* s_Instance;
        };

        Application* createApplication();
    }
}

#endif //_TRENDER_CORE_APPLICATION_H_