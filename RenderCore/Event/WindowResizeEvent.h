#ifndef _TRENDER_EVENT_WINDOWRESIZEEVENT_H_
#define _TRENDER_EVENT_WINDOWRESIZEEVENT_H_

#include "Event.h"
#include "EventDispatcher.h"

namespace TRender {
    namespace Event{
        class WindowResizeEvent : public Event
        {
        public:
            WindowResizeEvent(unsigned int width, unsigned int height)
                : m_Width(width), m_Height(height) {}

            unsigned int getWidth() const { 
                return m_Width; 
            }
            unsigned int getHeight() const { 
                return m_Height; 
            }

            std::string toString() const override
            {
                std::stringstream ss;
                ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
                return ss.str();
            }

            static EventType getStaticType() { 
                return EventType::WindowResize; 
            }
			virtual EventType getEventType() const override { 
                return getStaticType(); 
            }
			virtual const char* getName() const override { 
                return "WindowResize"; 
            }

            virtual int getCategoryFlags() const override { 
                return (EventCategoryApplication); 
            }
        private:
            unsigned int m_Width, m_Height;
        };
    }
}

#endif //_TRENDER_EVENT_WINDOWRESIZEEVENT_H_