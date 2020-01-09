#include "TRender.h"

using namespace TRender;

class Game : public Core::Application {
public:
    Game() {

    }
    ~Game() {

    }
};

Core::Application* Core::createApplication(){
    return new Game();
}
