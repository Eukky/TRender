#include "ExampleLayer.h"

void ExampleLayer::onUpdate() {
    TR_CLIENT_INFO("ExampleLayer::onUpdate");
    if(Core::Input::isKeyPressed(TR_KEY_TAB)) {
        TR_CLIENT_TRACE("Tap key is pressed");
    }
}

void ExampleLayer::onEvent(Event::Event& event) {
    TR_CLIENT_INFO("{0}", event.toString());
}