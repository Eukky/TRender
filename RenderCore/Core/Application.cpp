#include "Application.h"
#include <iostream>

#define WINDOW_TITLE "TRender"
#define WINDOW_WIDTH 1080
#define WINDOW_HEIGHT 720

namespace TRender {
    namespace Core {
        Application::Application() {
            m_Window = std::unique_ptr<Window>(Window::Window(WINDOW_TITLE, WINDOW_WIDTH, WINDOW_HEIGHT));
        }
        Application::~Application() {

        }

        void Application::run() {
            while(m_Running){
                m_Window->update();
            }
        }
    }
}