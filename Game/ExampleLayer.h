#include "TRender.h"

using namespace TRender;

class ExampleLayer : public Core::Layer {
public:
    ExampleLayer() : Core::Layer("ExampleLayer") {}

    void onUpdate() override;
    void onEvent(Event::Event& event) override;
    virtual void onImguiRender() override;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
};
