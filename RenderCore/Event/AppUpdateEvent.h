#ifndef _TRENDER_EVENT_APPUPDATEEVENT_H_
#define _TRENDER_EVENT_APPUPDATEEVENT_H_

#include "Event.h"
#include "EventDispatcher.h"

namespace TRender {
    namespace Event{
        class AppUpdateEvent : public Event {
        public:
            AppUpdateEvent() = default;

            static EventType getStaticType() { 
                return EventType::AppUpdate; 
            }
			virtual EventType getEventType() const override { 
                return getStaticType(); 
            }
			virtual const char* getName() const override { 
                return "AppUpdate"; 
            }

            virtual int getCategoryFlags() const override { 
                return (EventCategoryApplication); 
            }
        };
    }
}

#endif //_TRENDER_EVENT_APPUPDATEEVENT_H_