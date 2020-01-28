#ifndef _TRENDER_CORE_INPUT_H_
#define _TRENDER_CORE_INPUT_H_

#include <utility>
#include <memory>

namespace TRender {
    namespace Core {
        class Input {
        public:
            Input() {};
            ~Input() {};

            Input(const Input&) = delete; //删除默认拷贝构造函数
            Input& operator=(const Input&) = delete;

            static bool isKeyPressed(int keycode);
            static bool isMouseButtonPressed(int button);
            static std::pair<float, float> getMousePosition();
            static float getMouseX();
            static float getMouseY();

        private:
            bool isKeyPressedImpl(int keycode);
            bool isMouseButtonPressedImpl(int button);
            std::pair<float, float> getMousePositionImpl();
            float getMouseXImpl();
            float getMouseYImpl();
        private:
            static std::unique_ptr<Input> s_Instance;
        };
    }
}

#endif //_TRENDER_CORE_INPUT_H_