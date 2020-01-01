#ifndef _TRENDER_CORE_ENTRYPOINT_H_
#define _TRENDER_CORE_ENTRYPOINT_H_

#include "Application.h"
#include "Common/Tlog.h"

using namespace TRender;

extern Core::Application* Core::createApplication(); 

int main() {

    if(TRender::Common::Tlog::Init()) {
        TR_CORE_TRACE("Init Tlog!");
    }
    

    auto app = Core::createApplication();
    TR_CORE_TRACE("Game create success");

    TR_CORE_TRACE("Game start run");
    app->run();
    delete app;
}

#endif //_TRENDER_CORE_ENTRYPOINT_H_