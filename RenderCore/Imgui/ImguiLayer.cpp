#include "ImguiLayer.h"
#include "Common/Tlog.h"
#include "Core/Layer.h"
#include "Core/Window.h"
#include "Core/Application.h"
namespace TRender {
    namespace Imgui {
        ImguiLayer::ImguiLayer() : Layer("ImguiLayer") {

        }
        
        ImguiLayer::~ImguiLayer() {

        }

        void ImguiLayer::onAttach() {
            ImGui::CreateContext();
            ImGui::StyleColorsDark();

            ImGuiIO& io = ImGui::GetIO();
            (void)io;
            io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
            io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
            io.ConfigFlags |= ImGuiConfigFlags_NavEnableSetMousePos;

    		ImGuiStyle& style = ImGui::GetStyle();

            if (io.ConfigFlags)
            {   
                style.WindowRounding = 0.0f;
                style.Colors[ImGuiCol_WindowBg].w = 1.0f;
            }

            Core::Application& app = Core::Application::getInstance();
            io.DisplaySize = ImVec2(app.getWindow().getWidth(), app.getWindow().getHeight());
            GLFWwindow* window = static_cast<GLFWwindow*>(app.getWindow().getWindow());
            ImGui_ImplGlfw_InitForOpenGL(window, true); //true:输入给imgui false:输入给Event
            ImGui_ImplOpenGL3_Init("#version 410");
        }

        void ImguiLayer::onDetach() {
            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplGlfw_Shutdown();
            // ImGui::DestroyContext();
        }

//         void ImguiLayer::onUpdate() {
//             glfwPollEvents();
//             ImGuiIO& io = ImGui::GetIO();
//             (void)io;
// //
//             Core::Application& app = Core::Application::getInstance();
//             io.DisplaySize = ImVec2(app.getWindow().getWidth(), app.getWindow().getHeight());

//             GLFWwindow* window = static_cast<GLFWwindow*>(app.getWindow().getWindow());
//             ImGui_ImplGlfw_InitForOpenGL(window, false);
//             ImGui_ImplOpenGL3_NewFrame();
//             ImGui_ImplGlfw_NewFrame();
//             ImGui::NewFrame();

//             static bool show = true;
//             ImGui::ShowDemoWindow(&show);

//             ImGui::Render();
//             ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
//         }

        // void ImguiLayer::onEvent(Event::Event& event) {
            
        // }

        void ImguiLayer::begin() {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

        }

        void ImguiLayer::end() {
            ImGuiIO& io = ImGui::GetIO();
            Core::Application& app = Core::Application::getInstance();
            io.DisplaySize = ImVec2(app.getWindow().getWidth(), app.getWindow().getHeight());
            GLFWwindow* window = static_cast<GLFWwindow*>(app.getWindow().getWindow());

            // Rendering
            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            
            if (io.ConfigFlags)
            {
                GLFWwindow* backup_current_context = glfwGetCurrentContext();
                glfwMakeContextCurrent(backup_current_context);
		    }
        }
    }
}