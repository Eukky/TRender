#include "TRender.h"
#include "EntryPoint.h"
#include "ExampleLayer.h"

using namespace TRender;

class Game : public Core::Application {
public:
    Game() {
        pushLayer(new ExampleLayer());
        pushOverlay(new Gui::ImguiLayer());
    }
    ~Game() {

    }
};

Core::Application* Core::createApplication(){
    return new Game();
}
