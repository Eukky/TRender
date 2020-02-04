#include "TRender.h"

using namespace TRender;

class ExampleLayer : public Core::Layer {
public:
    ExampleLayer() : Core::Layer("ExampleLayer") {}

    void onUpdate() override;
    void onEvent(Event::Event& event) override;
    virtual void onImguiRender() override;
};
