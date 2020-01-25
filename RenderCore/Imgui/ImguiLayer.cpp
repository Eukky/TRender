#include "ImguiLayer.h"

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
            io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
            io.ConfigFlags |= ImGuiConfigFlags_NavEnableSetMousePos;

            // define key map
            io.KeyMap[ImGuiKey_Tab] = GLFW_KEY_TAB;
            io.KeyMap[ImGuiKey_LeftArrow] = GLFW_KEY_LEFT;
            io.KeyMap[ImGuiKey_RightArrow] = GLFW_KEY_RIGHT;
            io.KeyMap[ImGuiKey_UpArrow] = GLFW_KEY_UP;
            io.KeyMap[ImGuiKey_DownArrow] = GLFW_KEY_DOWN;
            io.KeyMap[ImGuiKey_PageUp] = GLFW_KEY_PAGE_UP;
            io.KeyMap[ImGuiKey_PageDown] = GLFW_KEY_PAGE_DOWN;
            io.KeyMap[ImGuiKey_Home] = GLFW_KEY_HOME;
            io.KeyMap[ImGuiKey_End] = GLFW_KEY_END;
            io.KeyMap[ImGuiKey_Insert] = GLFW_KEY_INSERT;
            io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
            io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
            io.KeyMap[ImGuiKey_Space] = GLFW_KEY_SPACE;
            io.KeyMap[ImGuiKey_Enter] = GLFW_KEY_ENTER;
            io.KeyMap[ImGuiKey_Escape] = GLFW_KEY_ESCAPE;
            io.KeyMap[ImGuiKey_A] = GLFW_KEY_A;
            io.KeyMap[ImGuiKey_C] = GLFW_KEY_C;
            io.KeyMap[ImGuiKey_V] = GLFW_KEY_V;
            io.KeyMap[ImGuiKey_X] = GLFW_KEY_X;
            io.KeyMap[ImGuiKey_Y] = GLFW_KEY_Y;
            io.KeyMap[ImGuiKey_Z] = GLFW_KEY_Z;

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