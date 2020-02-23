#include "BaseShader.h"
#include "Common/CommonHead.h"
#include "GraphicsAPI.h"
#include "BaseGraphics.h"
#include "Graphics/GLGraphics/GLShader.h"

namespace TRender {
    namespace Graphics {
        std::shared_ptr<BaseShader> BaseShader::create(const std::string& filepath) {
            switch(BaseGraphics::getAPI()) {
                case GraphicsAPI::GraphicsAPIList::NONE: {
                    TR_CORE_ASSERT(false, "RendererAPI::None! Please choose a kind of Render API"); 
                    return nullptr;
                }
                case GraphicsAPI::GraphicsAPIList::OPENGL: {
                    // return std::make_shared<GLShader>(filepath);
                    return std::shared_ptr<GLShader>(new GLShader(filepath));
                }
                case GraphicsAPI::GraphicsAPIList::VALKUN: {
                    TR_CORE_ASSERT(false, "RendererAPI::VALKUN is not supported currently"); 
                    return nullptr;
                }
            }
            return nullptr;
        }

        std::shared_ptr<BaseShader> BaseShader::create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc) {
            switch(BaseGraphics::getAPI()) {
                case GraphicsAPI::GraphicsAPIList::NONE: {
                    TR_CORE_ASSERT(false, "RendererAPI::None! Please choose a kind of Render API"); 
                    return nullptr;
                }
                case GraphicsAPI::GraphicsAPIList::OPENGL: {
                    // return std::make_shared<GLShader>(name, vertexSrc, fragmentSrc);
                    return std::shared_ptr<GLShader>(new GLShader(name, vertexSrc, fragmentSrc));
                }
                case GraphicsAPI::GraphicsAPIList::VALKUN: {
                    TR_CORE_ASSERT(false, "RendererAPI::VALKUN is not supported currently"); 
                    return nullptr;
                }
            }
            return nullptr;
        }
    }
}