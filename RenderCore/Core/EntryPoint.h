#ifndef _TRENDER_CORE_ENTRYPOINT_H_
#define _TRENDER_CORE_ENTRYPOINT_H_

#include "Application.h"
// #include "Common/Thead.h"

using namespace TRender;

extern Core::Application* Core::createApplication(); 

int main() {

    auto app = Core::createApplication();
    app->run();
    delete app;
}

#endif //_TRENDER_CORE_ENTRYPOINT_H_