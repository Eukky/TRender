#ifndef _TRENDER_EVENT_APPTICKEVENT_H_
#define _TRENDER_EVENT_APPTICKEVENT_H_

#include "Event.h"
#include "EventDispatcher.h"

namespace TRender {
    namespace Event{
        class AppTickEvent : public Event {
        public:
            AppTickEvent() = default;

            static EventType getStaticType() { 
                return EventType::AppTick; 
            }
			virtual EventType getEventType() const override { 
                return getStaticType(); 
            }
			virtual const char* getName() const override { 
                return "AppTick"; 
            }

            virtual int getCategoryFlags() const override { 
                return (EventCategoryApplication); 
            }
        };
    }
}

#endif //_TRENDER_EVENT_APPTICKEVENT_H_