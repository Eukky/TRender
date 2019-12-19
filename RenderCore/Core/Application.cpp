#include "Application.h"
#include <iostream>
// #include "Common/Thead.h"
namespace TRender {
    namespace Core {
        Application::Application() {

        }
        Application::~Application() {

        }

        void Application::run() {
            while(1){
                std::cout << "run" << std::endl;
            }
        }
    }
}