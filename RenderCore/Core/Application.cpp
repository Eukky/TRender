#include "Application.h"
#include <iostream>

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
        }
        Application::~Application() {

        }

        void Application::run() {
            while(m_Running){
                glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
                glClear(GL_COLOR_BUFFER_BIT);
                m_Window->update();
                std::cout << "is running" << std::endl;
            }
        }
    }
}