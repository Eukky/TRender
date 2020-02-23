#include "ShaderLibrary.h"
#include "Common/CommonHead.h"

namespace TRender {
    namespace Graphics {
        void ShaderLibrary::add(const std::string& name, const std::shared_ptr<BaseShader>& shader) {
            TR_CORE_ASSERT(!exists(name), "Shader already exists!");
            m_Shader[name] = shader;
        }

        void ShaderLibrary::add(const std::shared_ptr<BaseShader>& shader) {
            const std::string& name = shader->getName();
            add(name, shader);
        }

        std::shared_ptr<BaseShader> ShaderLibrary::load(const std::string& filepath) {
            std::shared_ptr<BaseShader> shader = BaseShader::create(filepath);
            add(shader);
            return shader;
        }

        std::shared_ptr<BaseShader> ShaderLibrary::load(const std::string& name, const std::string& filepath) {
            std::shared_ptr<BaseShader> shader = BaseShader::create(filepath);
            add(name, shader);
            return shader;
        }

        std::shared_ptr<BaseShader> ShaderLibrary::get(const std::string& name) {
            TR_CORE_ASSERT(exists(name), "Shader not found!");
            return m_Shader[name];
        }

        bool ShaderLibrary::exists(const std::string& name) const {
            return m_Shader.find(name) != m_Shader.end();
        }

    }
}