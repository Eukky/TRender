#ifndef _TRENDER_EVENT_EVENT_H_
#define _TRENDER_EVENT_EVENT_H_

#include <string>

namespace TRender {
    namespace Event {
        enum class EventType {
            None = 0,
            WindowClose = 1,
            WindowResize = 2,
            WindowFouse = 3,
            WindowLostFouse = 4,
            WindowMoved = 5,
            AppTick = 6,
            AppUpdate = 7,
            AppRender = 8,
            KeyPressed = 9,
            KeyReleased = 10,
            KeyTyped = 11,
            MouseButtonPressed = 12,
            MouseButtonReleased = 13,
            MouseMoved = 14,
            MouseScrolled = 15
        };

        enum EventCategory {
            None = 0,
            EventCategoryApplication = (1 << 0),
            EventCategoryInput = (1 << 1),
            EventCategoryKeyboard = (1 << 2),
            EventCategoryMouse = (1 << 3),
            EventCategoryMouseClick = (1 << 4)
        };

        class Event {
        public:
            bool handled = false;

            virtual EventType getEventType() const = 0;
            virtual const char* getName() const = 0;
            virtual int getCategoryFlags() const = 0;
            virtual std::string toString() const { return getName(); }

            bool isInCategory(EventCategory category) {
                return getCategoryFlags() & category;
            }

        };

        std::ostream& operator<<(std::ostream& os, const Event& e) {
            return os << e.toString();
        }
    }
}

#endif //_TRENDER_EVENT_EVENT_H_