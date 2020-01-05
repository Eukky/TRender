#ifndef _TRENDER_EVENT_EVENTDISPATHCER_H_
#define _TRENDER_EVENT_EVENTDISPATHCER_H_

#include "Event.h"

namespace TRender {
    namespace Event {
        class EventDispatcher {
        public:
            EventDispatcher(Event& event) : m_Event(event) {}

            template <typename T, typename F>
            bool dispatch(const F& func) {
                if(m_Event.getEventType() == T::getStaticType()) {
                    m_Event.handled = func(static_cast<T&>(m_Event));
                    return true;
                }
                return false;
            }
        private:
            Event& m_Event;
        };
    }
}

#endif //_TRENDER_EVENT_EVENTDISPATHCER_H_