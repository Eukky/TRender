#include "ExampleLayer.h"
#include <glm/gtc/type_ptr.hpp>

ExampleLayer::ExampleLayer() : Core::Layer("ExampleLayer") {

    std::string flatColorShaderVertexSrc = R"(
			#version 330 core
            
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";

	std::string flatColorShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			
			uniform vec3 u_Color;

			void main()
			{
				color = vec4(u_Color, 1.0);
			}
		)";

    m_Shader = Graphics::BaseShader::create("shader", flatColorShaderVertexSrc, flatColorShaderFragmentSrc);
}

void ExampleLayer::onUpdate() {
    // TR_CLIENT_INFO("ExampleLayer::onUpdate");
    if(Core::Input::isKeyPressed(TR_KEY_TAB)) {
        TR_CLIENT_TRACE("Tap key is pressed");
    }

    m_Shader->bind();
    glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
    m_Shader->setFloat3("u_Color", m_SquareColor);
}

void ExampleLayer::onEvent(Event::Event& event) {
    if(event.getEventType() == Event::EventType::KeyPressed) {
        Event::KeyPressedEvent& e = (Event::KeyPressedEvent&)event;
        TR_CLIENT_TRACE("{0}", (char)e.getKeyCode());
    }
    // TR_CLIENT_INFO("{0}", event.toString());
}

void ExampleLayer::onImguiRender() {
    ImGui::Begin("begin");
    ImGui::Text("hello");
    
    ImGui::ColorEdit3("clear color", (float*)&clear_color);
	ImGui::ShowDemoWindow();
    
	ImGui::End();

    Core::Application& app = Core::Application::getInstance();
    GLFWwindow* window = static_cast<GLFWwindow*>(app.getWindow().getWindow());
    int display_w, display_h;
    glfwMakeContextCurrent(window);
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
}