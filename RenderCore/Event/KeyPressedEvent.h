#ifndef _TRENDER_EVENT_KEYPRESSEDEVENT_H_
#define _TRENDER_EVENT_KEYPRESSEDEVENT_H_

#include "KeyEvent.h"

namespace TRender {
    namespace Event {
        class KeyPressedEvent : public KeyEvent {
        public:
            KeyPressedEvent(int keycode, int repeatCount) 
                : KeyEvent(keycode), m_RepeatCount(repeatCount) {}

            int getRepeatCount() const {
                return m_RepeatCount;
            }

            std::string toString() const override {
                std::stringstream ss;
                ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
                return ss.str();
            }

            static EventType getStaticType() { 
                return EventType::KeyPressed; 
            }
			virtual EventType getEventType() const override { 
                return getStaticType(); 
            }
			virtual const char* getName() const override { 
                return "KeyPressed"; 
            }
        private:
            int m_RepeatCount;
        };
    }
}

#endif //_TRENDER_EVENT_KEYPRESSEDEVENT_H_