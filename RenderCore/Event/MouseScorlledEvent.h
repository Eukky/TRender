#ifndef _TRENDER_EVENT_MOUSESCORLLEDEVENT_H_
#define _TRENDER_EVENT_MOUSESCORLLEDEVENT_H_

#include <string>
#include "Event.h"
#include "EventDispatcher.h"

namespace TRender {
    namespace Event {
        class MousescrolledEvent : public Event {
        public:
            MouseScrolledEvent(float xOffset, float yOffset)
			    : m_XOffset(xOffset), m_YOffset(yOffset) {}

		    float getXOffset() const { return m_XOffset; }
		    float getYOffset() const { return m_YOffset; }

            std::string toString() const override
            {
                std::stringstream ss;
                ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset;
                return ss.str();
            }

            static EventType getStaticType() { 
                return EventType::MouseScorlled; 
            }
			virtual EventType getEventType() const override { 
                return GetStaticType(); 
            }
			virtual const char* getName() const override { 
                return "MouseScorlled"; 
            }

            virtual int GetCategoryFlags() const override { 
                return (EventCategoryMouse | EventCategoryInput); 
            }
        private:
            float m_XOffset, m_YOffset;
        };
    }
}

#endif //_TRENDER_EVENT_MOUSESCORLLEDEVENT_H_