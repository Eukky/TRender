#include "TRender.h"
#include "EntryPoint.h"
#include "ExampleLayer.h"

// #define _TRENDER_IMGUI_
#define _TRENDER_NUKLEAR_
// #include "Gui/GuiHead.h"
#include "Gui/Nuklear/NuklearLayer.h"

using namespace TRender;

class Game : public Core::Application {
public:
    Game() {
        pushLayer(new ExampleLayer());
        // pushOverlay(new Gui::ImguiLayer());
        pushOverlay(new Gui::NuklearLayer());
    }
    ~Game() {

    }
};

Core::Application* Core::createApplication(){
    return new Game();
}
