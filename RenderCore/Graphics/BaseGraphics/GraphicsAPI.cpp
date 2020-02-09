#include "GraphicsAPI.h"

namespace TRender {
    namespace Graphics {
        GraphicsAPI::GraphicsAPIList GraphicsAPI::m_API = GraphicsAPI::GraphicsAPIList::OPENGL;

        GraphicsAPI::GraphicsAPIList GraphicsAPI::getAPI() {
            return m_API;
        }
    }
}