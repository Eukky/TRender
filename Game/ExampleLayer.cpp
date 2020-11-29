#include "ExampleLayer.h"
#include <glm/gtc/type_ptr.hpp>
#include <Graphics/BaseGraphics/GraphicsManager.h>

ExampleLayer::ExampleLayer() : Core::Layer("ExampleLayer"), m_CameraController(1280.0f / 720.0f, true), m_OrthoCameraController(1280.0f / 720.0f, true)
{

    m_SquareVA = Graphics::VertexArray::create();
    float squareVertices[5 * 4] = {
        -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
        0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
        0.5f, 0.5f, 0.0f, 1.0f, 1.0f,
        -0.5f, 0.5f, 0.0f, 0.0f, 1.0f};
    std::shared_ptr<Graphics::VertexBuffer> squareVB = Graphics::VertexBuffer::create(squareVertices, sizeof(squareVertices));
    squareVB->setLayout({
        {Graphics::ShaderDataType::Float3, "a_Position"},
        {Graphics::ShaderDataType::Float2, "a_TexCoord"},
    });
    m_SquareVA->addVertexBuffer(squareVB);

    uint32_t squareIndices[6] = {0, 1, 2, 2, 3, 0};
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
				color = vec4(u_Color, 0.5);
			}
		)";

    // std::string flatColorShaderFragmentSrc = R"(
    //     #version 330 core
    //     in vec3 v_Position;
    //     layout(location = 0) out vec4 fragColor;
    //     const float PI = 3.14159265;

    //     vec2 rotate(vec2 v, float a) {
    //         float sinA = sin(a);
    //         float cosA = cos(a);
    //         return vec2(v.x * cosA - v.y * sinA, v.y * cosA + v.x * sinA);
    //     }

    //     float square(vec2 uv, float d) {
    //         return max(abs(uv.x), abs(uv.y)) - d;
    //     }

    //     float smootheststep(float edge0, float edge1, float x)
    //     {
    //         x = clamp((x - edge0)/(edge1 - edge0), 0.0, 1.0) * 3.14159265;
    //         return 0.5 - (cos(x) * 0.5);
    //     }

    //     void main()
    //     {
    //         vec2 uv = v_Position.xy / iResolution.xy;
    //         uv = uv * 2.0 - 1.0;
    //         uv.x *= iResolution.x / iResolution.y;
    //         uv *= 1.5;

    //         float blurAmount = -0.005 * 1080.0 / iResolution.y;

    //         float period = 2.0;
    //         float time = iTime / period;
    //         time = mod(time, 1.0);
    //         time = smootheststep(0.0, 1.0, time);

    //         fragColor = vec4(0.0, 0.0, 0.0, 1.0);
    //         for (int i = 0; i < 9; i++) {
    //             float n = float(i);
    //             float size = 1.0 - n / 9.0;
    //             float rotateAmount = (n * 0.5 + 0.25) * PI * 2.0;
    //             fragColor.rgb = mix(fragColor.rgb, vec3(1.0), smoothstep(0.0, blurAmount, square(rotate(uv, -rotateAmount * time), size)));
    //             float blackOffset = mix(1.0 / 4.0, 1.0 / 2.0, n / 9.0) / 9.0;
    //             fragColor.rgb = mix(fragColor.rgb, vec3(0.0), smoothstep(0.0, blurAmount, square(rotate(uv, -(rotateAmount + PI / 2.0) * time), size - blackOffset)));
    //         }
    //     }
    // )";

    m_Shader = Graphics::BaseShader::create("shader", flatColorShaderVertexSrc, flatColorShaderFragmentSrc);
}

void ExampleLayer::onUpdate()
{
    // TR_CLIENT_INFO("ExampleLayer::onUpdate");
    if (Core::Input::isKeyPressed(TR_KEY_TAB))
    {
        TR_CLIENT_TRACE("Tap key is pressed");
    }

    // m_CameraController.onUpdate();
    m_OrthoCameraController.onUpdate();

    Graphics::GraphicsManager::setClearColor({1.0f, 1.0f, 1.0f, 1.0f});
    Graphics::GraphicsManager::clear();

    // Graphics::BaseGraphics::BeginScene(m_CameraController.getCamera());
    Graphics::BaseGraphics::BeginScene(m_OrthoCameraController.getCamera());

    m_Shader->bind();
    glm::vec3 m_SquareColor = {1.0f, 0.0f, 0.0f};
    m_Shader->setFloat3("u_Color", m_SquareColor);
    glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
    glm::vec3 pos(0.11f, 0.11f, 0.0f);
    glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
    Graphics::BaseGraphics::submit(m_Shader, m_SquareVA, transform);
    // glClearColor(1.0f,1.0f,1.0f,1.0f);
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

    Graphics::BaseGraphics::EndScene();
}

void ExampleLayer::onEvent(Event::Event &event)
{
    if (event.getEventType() == Event::EventType::KeyPressed)
    {
        Event::KeyPressedEvent &e = (Event::KeyPressedEvent &)event;
        TR_CLIENT_TRACE("{0}", (char)e.getKeyCode());
    }
    //  m_CameraController.onEvent(event);
    m_OrthoCameraController.onEvent(event);
    TR_CLIENT_INFO("{0}", event.toString());
}

void ExampleLayer::onImguiRender()
{
    ImGui::Begin("begin");
    ImGui::Text("hello");

    ImGui::ColorEdit3("clear color", (float *)&clear_color);
    ImGui::ShowDemoWindow();

    ImGui::End();

    Core::Application &app = Core::Application::getInstance();
    GLFWwindow *window = static_cast<GLFWwindow *>(app.getWindow().getWindow());
    int display_w, display_h;
    glfwMakeContextCurrent(window);
    glfwGetFramebufferSize(window, &display_w, &display_h);
    glViewport(0, 0, display_w, display_h);
    glClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);
    glClear(GL_COLOR_BUFFER_BIT);
}