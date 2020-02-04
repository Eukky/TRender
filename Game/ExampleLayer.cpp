#include "ExampleLayer.h"
#include <glm/gtc/type_ptr.hpp>
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