#include "ExampleLayer.h"
#include <glm/gtc/type_ptr.hpp>
#include <Graphics/BaseGraphics/GraphicsManager.h>

ExampleLayer::ExampleLayer() : Core::Layer("ExampleLayer") {

    m_SquareVA = Graphics::VertexArray::create();
    float squareVertices[5 * 4] = {
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
            0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
            -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
    };
    std::shared_ptr<Graphics::VertexBuffer> squareVB = Graphics::VertexBuffer::create(squareVertices, sizeof(squareVertices));
    squareVB->setLayout({
        {Graphics::ShaderDataType::Float3, "a_Position"},
        {Graphics::ShaderDataType::Float2, "a_TexCoord"},
    });
    m_SquareVA->addVertexBuffer(squareVB);

    uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
    std::shared_ptr<Graphics::IndexBuffer> squareIB = Graphics::IndexBuffer::create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t));
    m_SquareVA->setIndexBuffer(squareIB);

    std::string flatColorShaderVertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = vec4(a_Position, 1.0);
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

    Graphics::GraphicsManager::setClearColor({0.1f, 0.1f, 0.1f, 1.0f});
    Graphics::GraphicsManager::clear();

    m_Shader->bind();
    glm::vec3 m_SquareColor = { 1.0f, 1.0f, 1.0f };
    m_Shader->setFloat3("u_Color", m_SquareColor);
    glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
    glm::vec3 pos(0.11f, 0.11f, 0.0f);
    glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
    Graphics::BaseGraphics::submit(m_Shader, m_SquareVA, transform);
    glClearColor(1.0f,1.0f,1.0f,1.0f);
}

void ExampleLayer::onEvent(Event::Event& event) {
    if(event.getEventType() == Event::EventType::KeyPressed) {
        Event::KeyPressedEvent& e = (Event::KeyPressedEvent&)event;
        TR_CLIENT_TRACE("{0}", (char)e.getKeyCode());
    }
    // TR_CLIENT_INFO("{0}", event.toString());
}

void ExampleLayer::onImguiRender() {
//     ImGui::Begin("begin");
//     ImGui::Text("hello");
//
//     ImGui::ColorEdit3("clear color", (float*)&clear_color);
//	 ImGui::ShowDemoWindow();
//
//	 ImGui::End();
//
//     Core::Application& app = Core::Application::getInstance();
//     GLFWwindow* window = static_cast<GLFWwindow*>(app.getWindow().getWindow());
//     int display_w, display_h;
//     glfwMakeContextCurrent(window);
//     glfwGetFramebufferSize(window, &display_w, &display_h);
//     glViewport(0, 0, display_w, display_h);
//     glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
//     glClear(GL_COLOR_BUFFER_BIT);
}