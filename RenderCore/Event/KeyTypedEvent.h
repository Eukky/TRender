#ifndef _TRENDER_EVENT_KEYTYPEDEVENT_H_
#define _TRENDER_EVENT_KEYTYPEDEVENT_H_

#include "KeyEvent.h"

namespace TRender {
    namespace Event {
        class KeyTypedEvent : public KeyEvent {
        public:
            KeyTypedEvent(int keycode) : KeyEvent(keycode) {}

            std::string toString() const override {
                std::stringstream ss;
                ss << "KeyTypedEvent: " << m_KeyCode;
            }

            static EventType getStaticType() { 
                return EventType::KeyTyped; 
            }
			virtual EventType getEventType() const override { 
                return getStaticType(); 
            }
			virtual const char* getName() const override { 
                return "KeyTyped"; 
            }
       
        };
    }
}

#endif //_TRENDER_EVENT_KEYTYPEDEVENT_H_