#ifndef _TRENDER_CORE_LAYERS_H_
#define _TRENDER_CORE_LAYERS_H_

#include "Event/Event.h"
#include <string>

namespace TRender {
    namespace Core {
        class Layer {
        public:
            Layer(const std::string& name = "Layer");
            virtual ~Layer() = default;

            virtual void onAttach() {}
            virtual void onDetach() {}
            virtual void onUpdate() {}
            virtual void onImGuiRender() {}
            virtual void onEvent(Event::Event& event) {}

            const std::string& getName() const {
                return m_DebugName;
            }
        protected:
            std::string m_DebugName;
        };
    }
}

#endif //_TRENDER_CORE_LAYERS_H_