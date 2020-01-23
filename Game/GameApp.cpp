#include "TRender.h"
#include "EntryPoint.h"
#include "ExampleLayer.h"

using namespace TRender;

class Game : public Core::Application {
public:
    Game() {
        pushLayer(new ExampleLayer());
    }
    ~Game() {

    }
};

Core::Application* Core::createApplication(){
    return new Game();
}
