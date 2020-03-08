#include "GraphicsAPI.h"
#include "Common/CommonHead.h"
#include "Graphics/GLGraphics/GLGraphicsAPI.h"
namespace TRender {
    namespace Graphics {
        GraphicsAPI::GraphicsAPIList GraphicsAPI::s_API = GraphicsAPI::GraphicsAPIList::Opengl;

        GraphicsAPI::GraphicsAPI() {

        }

        GraphicsAPI::~GraphicsAPI() {
            
        }

        GraphicsAPI::GraphicsAPIList GraphicsAPI::getAPI() {
            return s_API;
        }

        std::unique_ptr<GraphicsAPI> GraphicsAPI::create() {
            switch(s_API) {
                case GraphicsAPI::GraphicsAPIList::None: {
                    TR_CORE_ASSERT(false, "RendererAPI::None! Please choose a kind of Render API"); 
                    return nullptr;
                }
                case GraphicsAPI::GraphicsAPIList::Opengl: {
                    // return std::unique_ptr<GLGraphicsAPI>(new GLGraphicsAPI);
                    return std::make_unique<GLGraphicsAPI>();
                }
                case GraphicsAPI::GraphicsAPIList::Valkun: {
                    TR_CORE_ASSERT(false, "RendererAPI::VALKUN is not supported currently"); 
                    return nullptr;
                }
            }
          
        }
    }
}