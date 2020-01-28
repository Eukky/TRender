#include "ExampleLayer.h"

void ExampleLayer::onUpdate() {
    // TR_CLIENT_INFO("ExampleLayer::onUpdate");
    if(Core::Input::isKeyPressed(TR_KEY_TAB)) {
        TR_CLIENT_TRACE("Tap key is pressed");
    }
}

void ExampleLayer::onEvent(Event::Event& event) {
    if(event.getEventType() == Event::EventType::KeyPressed) {
        Event::KeyPressedEvent& e = (Event::KeyPressedEvent&)event;
        TR_CLIENT_TRACE("{0}", (char)e.getKeyCode());
    }
    // TR_CLIENT_INFO("{0}", event.toString());
}