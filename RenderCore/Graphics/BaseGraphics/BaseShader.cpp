#include "BaseShader.h"
#include "Common/CommonHead.h"
#include "GraphicsAPI.h"
#include "BaseGraphics.h"
#include "Graphics/GLGraphics/GLShader.h"

namespace TRender {
    namespace Graphics {
        std::shared_ptr<BaseShader> BaseShader::create(const std::string& filepath) {
            switch(BaseGraphics::getAPI()) {
                case GraphicsAPI::GraphicsAPIList::None: {
                    TR_CORE_ASSERT(false, "RendererAPI::None! Please choose a kind of Render API"); 
                    return nullptr;
                }
                case GraphicsAPI::GraphicsAPIList::Opengl: {
                    // return std::make_shared<GLShader>(filepath);
                    return std::shared_ptr<GLShader>(new GLShader(filepath));
                }
                case GraphicsAPI::GraphicsAPIList::Valkun: {
                    TR_CORE_ASSERT(false, "RendererAPI::Valkun is not supported currently"); 
                    return nullptr;
                }
            }
            return nullptr;
        }

        std::shared_ptr<BaseShader> BaseShader::create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc) {
            switch(BaseGraphics::getAPI()) {
                case GraphicsAPI::GraphicsAPIList::None: {
                    TR_CORE_ASSERT(false, "RendererAPI::None! Please choose a kind of Render API"); 
                    return nullptr;
                }
                case GraphicsAPI::GraphicsAPIList::Opengl: {
                    // return std::make_shared<GLShader>(name, vertexSrc, fragmentSrc);
                    return std::shared_ptr<GLShader>(new GLShader(name, vertexSrc, fragmentSrc));
                }
                case GraphicsAPI::GraphicsAPIList::Valkun: {
                    TR_CORE_ASSERT(false, "RendererAPI::VALKUN is not supported currently"); 
                    return nullptr;
                }
            }
            return nullptr;
        }

        void BaseShader::checkCompileErrors(GLuint shader, std::string type) {
            GLint success;
            GLchar infoLog[1024];
            if(type != "PROGRAM"){
                glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
                if(!success){
                    glGetShaderInfoLog(shader, 1024, NULL, infoLog);
                    TR_CORE_ERROR("ERROR::SHADER_COMPILATION_ERROR of type: {0}::{1}", type, infoLog);
                }
            }else {
                glGetProgramiv(shader, GL_LINK_STATUS, & success);
                if(!success){
                    glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                    TR_CORE_ERROR("ERROR::SHADER_LINKING_ERROR of type: {0}::{1}", type, infoLog);
                }
            }
        }
    }
}