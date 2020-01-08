#ifndef _TRENDER_EVENT_MOUSEBUTTONEVENT_H_
#define _TRENDER_EVENT_MOUSEBUTTONEVENT_H_

#include <string>
#include "Event.h"
#include "EventDispatcher.h"

namespace TRender {
    namespace Event {
        class MouseButtonEvent : public Event {
        public:
             MouseButtonEvent(int button)
                : m_Button(button) {}
            int getMouseButton() const { return m_Button; }

            virtual int GetCategoryFlags() const override { 
                return (EventCategoryMouse | EventCategoryInput); 
            }
        protected:
            int m_Button;
        };
    }
}
#endif //_TRENDER_EVENT_MOUSEBUTTONEVENT_H_