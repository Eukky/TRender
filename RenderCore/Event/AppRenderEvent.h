#ifndef _TRENDER_EVENT_APPRENDEREVENT_H_
#define _TRENDER_EVENT_APPRENDEREVENT_H_

#include "Event.h"
#include "EventDispatcher.h"

namespace TRender {
    namespace Event{
        class AppRenderEvent : public Event {
        public:
            AppRenderEvent() = default;

            static EventType getStaticType() { 
                return EventType::AppRender; 
            }
			virtual EventType getEventType() const override { 
                return getStaticType(); 
            }
			virtual const char* getName() const override { 
                return "AppRender"; 
            }

            virtual int getCategoryFlags() const override { 
                return (EventCategoryApplication); 
            }
        };
    }
}

#endif //_TRENDER_EVENT_APPRENDEREVENT_H_