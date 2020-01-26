#include "Input.h"
#include "Application.h"
namespace TRender {
    namespace Core {

        bool Input::isKeyPressed(int keycode) {
            return s_Instance->isKeyPressedImpl(keycode);
        }

        bool Input::isMouseButtonPressed(int button) {
            return s_Instance->isMouseButtonPressedImpl(button);
        }

        std::pair<float, float> Input::getMousePosition() {
            return s_Instance->getMousePositionImpl();
        }

        float Input::getMouseX() {
            return s_Instance->getMouseXImpl();
        }

        float Input::getMouseY() {
            return s_Instance->getMouseYImpl();
        }

        bool Input::isKeyPressedImpl(int keycode) {
            auto window = static_cast<GLFWwindow*>(Application::getInstance().getWindow().getWindow());
            auto state = glfwGetKey(window, keycode);
            return (state == GLFW_PRESS || state == GLFW_REPEAT);
        }

        bool Input::isMouseButtonPressedImpl(int button) {
            auto window = static_cast<GLFWwindow*>(Application::getInstance().getWindow().getWindow());
            auto state = glfwGetMouseButton(window, button);
            return state == GLFW_PRESS;
        }

        std::pair<float, float> Input::getMousePositionImpl() {
            auto window = static_cast<GLFWwindow*>(Application::getInstance().getWindow().getWindow());
            double xpos, ypos;
            glfwGetCursorPos(window, &xpos, &ypos);
            return {(float)xpos, (float)ypos};
        }

        float Input::getMouseXImpl() {
            auto[x, y] = getMousePositionImpl();
            return x;
        }

        float Input::getMouseYImpl() {
            auto[x, y] = getMousePositionImpl();
            return y;
        }
    }
}