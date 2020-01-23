#include "ExampleLayer.h"

void ExampleLayer::onUpdate() {
    TR_CLIENT_INFO("ExampleLayer::onUpdate");
}

void ExampleLayer::onEvent(Event::Event& event) {
    TR_CLIENT_INFO("{0}", event.toString());
}