#include "TRender.h"
#include <memory>

using namespace TRender;

class ExampleLayer : public Core::Layer {
    public:
        ExampleLayer();

        void onUpdate() override;
        void onEvent(Event::Event& event) override;
        virtual void onImguiRender() override;
        ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
    private:
        Graphics::ShaderLibrary m_ShaderLibrary;
        Graphics::BaseGraphics m_Render;
        std::shared_ptr<Graphics::BaseShader> m_Shader;
        std::shared_ptr<Graphics::VertexArray> m_SquareVA;
        
};
