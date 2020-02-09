#include "GraphicsAPI.h"

namespace TRender {
    namespace Graphics {
        GraphicsAPI::GraphicsAPIList m_API = GraphicsAPI::GraphicsAPIList::OPENGL;

        GraphicsAPI::GraphicsAPIList GraphicsAPI::getAPI() {
            return m_API;
        }
    }
}