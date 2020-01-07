#ifndef _TRENDER_EVENT_KEYRELEASEDEVENT_H_
#define _TRENDER_EVENT_KEYRELEASEDEVENT_H_

#include <string>
#include "KeyEvent.h"

namespace TRender {
    namespace Event {
        class KeyReleasedEvent : public KeyEvent {
        public:
            KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

            std::string toString() const override {
                std::stringstream ss;
                ss << "KeyReleasedEvent: " << m_KeyCode;
            }

            static EventType getStaticType() { 
                return EventType::KeyReleased; 
            }
			virtual EventType getEventType() const override { 
                return GetStaticType(); 
            }
			virtual const char* getName() const override { 
                return "KeyReleased"; 
            }
       
        };
    }
}

#endif //_TRENDER_EVENT_KEYRELEASEDEVENT_H_