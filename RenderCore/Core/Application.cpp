#include "Application.h"
#include "Common/CommonHead.h"

#define WINDOW_TITLE "TRender"
#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 720

namespace TRender {
    namespace Core {
        Application::Application() {
            m_Window = std::unique_ptr<Window>(new Window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT));
            //Does not support std::make_unique<T>()
            // m_Window = std::make_unique<Window>(Window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT));
            m_Window->createWindow();
            m_Window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
        }
        Application::~Application() {

        }

        void Application::onEvent(Event::Event& e) {
            
            TR_CORE_INFO("{0}", e.toString());

            Event::EventDispatcher dispatcher(e);
            dispatcher.dispatch<Event::WindowCloseEvent>(std::bind(&Application::onWindowClose, this, std::placeholders::_1));
            dispatcher.dispatch<Event::WindowResizeEvent>(std::bind(&Application::onWindowResize, this, std::placeholders::_1));
        }

        void Application::pushLayer(Layer* layer) {
            m_LayerStack.pushLayer(layer);
            layer->onAttach();
        }

        void Application::pushOverlay(Layer* overlay) {
            m_LayerStack.pushOverlay(overlay);
            overlay->onAttach();
        }

        void Application::popLayer(Layer* layer) {
            m_LayerStack.popLayer(layer);
            layer->onDetach();
        }

        void Application::popOverlay(Layer* layer) {
            m_LayerStack.popOverlay(layer);
            layer->onDetach();
        }

        void Application::run() {
            while(m_Running){
                glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT);
                for(Layer* layer : m_LayerStack) {
                    layer->onUpdate();
                }
                m_Window->update();
                // std::cout << "is running" << std::endl;
            }
        }

        bool Application::onWindowClose(Event::WindowCloseEvent& e) {
            m_Running = false;
            return true;
        }

        bool Application::onWindowResize(Event::WindowResizeEvent& e) {
            
            return true;
        }
    }
}