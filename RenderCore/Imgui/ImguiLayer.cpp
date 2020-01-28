#include "ImguiLayer.h"
#include "Common/Tlog.h"
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

            ImGui_ImplOpenGL3_Init("#version 410");
        }

        void ImguiLayer::onDetach() {

        }

        void ImguiLayer::onUpdate() {
            glfwPollEvents();
            ImGuiIO& io = ImGui::GetIO();
            (void)io;

            Core::Application& app = Core::Application::getInstance();
            io.DisplaySize = ImVec2(app.getWindow().getWidth(), app.getWindow().getHeight());
            
//            io.Fonts->AddFontDefault();
            // ImFontConfig config;
            // config.MergeMode = true;
            // config.GlyphMinAdvanceX = 13.0f; // Use if you want to make the icon monospaced
            // static const ImWchar icon_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
            // ImFont* font = io.Fonts->AddFontFromFileTTF("ProggyTiny.ttf", 13.0f, &config, icon_ranges);
            // ImGui::GetIO().FontDefault = font;
            GLFWwindow* window = static_cast<GLFWwindow*>(app.getWindow().getWindow());
            ImGui_ImplGlfw_InitForOpenGL(window, true);
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();

            static bool show = true;
            ImGui::ShowDemoWindow(&show);

            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        }

        void ImguiLayer::onEvent(Event::Event& event) {
            
        }

        void ImguiLayer::begin() {

        }

        void ImguiLayer::end() {

        }
    }
}