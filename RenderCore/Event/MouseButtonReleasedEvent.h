#ifndef _TRENDER_EVENT_MOUSEBUTTONRELEASEDEVENT_H_
#define _TRENDER_EVENT_MOUSEBUTTONRELEASEDEVENT_H_

#include <string>
#include "Event.h"
#include "EventDispatcher.h"
#include "MouseButtonEvent.h"

namespace TRender {
    namespace Event {
        class MouseButtonReleasedEvent : public MouseButtonEvent {
        public:
            MouseButtonReleasedEvent(int button)
                : MouseButtonEvent(button) {}

            std::string ToString() const override
            {
                std::stringstream ss;
                ss << "MouseButtonReleasedEvent: " << m_Button;
                return ss.str();
            }

            static EventType getStaticType() { 
                return EventType::MouseButtonReleased; 
            }
			virtual EventType getEventType() const override { 
                return GetStaticType(); 
            }
			virtual const char* getName() const override { 
                return "MouseButtonReleased"; 
            }
        };
    }
}
#endif //_TRENDER_EVENT_MOUSEBUTTONRELEASEDEVENT_H_