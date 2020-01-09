#ifndef _TRENDER_EVENT_KEYEVENT_H_
#define _TRENDER_EVENT_KEYEVENT_H_

#include "Event.h"
#include "EventDispatcher.h"

namespace TRender {
    namespace Event {
        class KeyEvent : public Event {
        public:
            int getKeyCode() const { 
                return m_KeyCode; 
            }

            virtual int getCategoryFlags() const override { 
                return (EventCategoryKeyboard | EventCategoryInput); 
            }
        protected:
            KeyEvent(int keycode) : m_KeyCode(keycode) {}

            int m_KeyCode;
        };
    }
}

#endif //_TRENDER_EVENT_KEYEVENT_H_