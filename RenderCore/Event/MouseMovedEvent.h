#ifndef _TRENDER_EVENT_MOUSEMOVEDEVENT_H_
#define _TRENDER_EVENT_MOUSEMOVEDEVENT_H_

#include <string>
#include "Event.h"
#include "EventDispatcher.h"

namespace TRender {
    namespace Event {
        class MouseMovedEvent : public Event {
        public:
            MouseMovedEvent(float x, float y)
                : m_MouseX(x), m_Mouse(y) {}

            float getX() const {
                return m_MouseX;
            }
            float getY() const {
                return m_MouseY;
            }

            std::string toString() const override {
                std::stringstream ss;
                ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY;
                return ss.str();
            }

            static EventType getStaticType() { 
                return EventType::MouseMoved; 
            }
			virtual EventType getEventType() const override { 
                return GetStaticType(); 
            }
			virtual const char* getName() const override { 
                return "MouseMoved"; 
            }

            virtual int GetCategoryFlags() const override { 
                return (EventCategoryMouse | EventCategoryInput); 
            }
        private:
            float m_MouseX, m_MouseY;
        };
    }
}

#endif //_TRENDER_EVENT_MOUSEMOVEDEVENT_H_