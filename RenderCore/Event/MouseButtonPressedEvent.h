#ifndef _TRENDER_EVENT_MOUSEBUTTONPRESSEDEVENT_H_
#define _TRENDER_EVENT_MOUSEBUTTONPRESSEDEVENT_H_

#include <string>
#include "Event.h"
#include "EventDispatcher.h"
#include "MouseButtonEvent.h"

namespace TRender {
    namespace Event {
        class MouseButtonPressedEvent : public MouseButtonEvent {
        public:
            MouseButtonPressedEvent(int button)
                : MouseButtonEvent(button) {}

            std::string ToString() const override
            {
                std::stringstream ss;
                ss << "MouseButtonPressedEvent: " << m_Button;
                return ss.str();
            }

            static EventType getStaticType() { 
                return EventType::MouseButtonPressed; 
            }
			virtual EventType getEventType() const override { 
                return GetStaticType(); 
            }
			virtual const char* getName() const override { 
                return "MouseButtonPressed"; 
            }
        };
    }
}
#endif //_TRENDER_EVENT_MOUSEBUTTONPRESSEDEVENT_H_