#include "GraphicsAPI.h"

namespace TRender {
    namespace Graphics {
        GraphicsAPI::GraphicsAPIList GraphicsAPI::m_API = GraphicsAPI::GraphicsAPIList::Opengl;

        GraphicsAPI::GraphicsAPIList GraphicsAPI::getAPI() {
            return m_API;
        }
    }
}