#ifndef _TRENDER_EVENT_WINDOWCLOSEEVENT_H_
#define _TRENDER_EVENT_WINDOWCLOSEEVENT_H_

#include <string>
#include "Event.h"
#include "EventDispatcher.h"

namespace TRender {
    namespace Event{
        class WindowCloseEvent : public Event
        {
        public:
            WindowCloseEvent() = default;

            static EventType getStaticType() { 
                return EventType::WindowClose; 
            }
			virtual EventType getEventType() const override { 
                return getStaticType(); 
            }
			virtual const char* getName() const override { 
                return "WindowClose"; 
            }

            virtual int getCategoryFlags() const override { 
                return (EventCategoryMouse | EventCategoryInput); 
            }
        };
    }
}

#endif //_TRENDER_EVENT_WINDOWCLOSEEVENT_H_