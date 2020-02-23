#include "ShaderLibrary.h"

namespace TRender {
    namespace Graphics {
        void ShaderLibrary::add(const std::string& name, const std::shared_ptr<BaseShader>& shader) {

        }

        void ShaderLibrary::add(const std::shared_ptr<BaseShader>& shader) {

        }

        std::shared_ptr<BaseShader> ShaderLibrary::load(const std::string& filepath) {

        }

        std::shared_ptr<BaseShader> ShaderLibrary::load(const std::string& name) {
            
        }

        std::shared_ptr<BaseShader> ShaderLibrary::load(const std::string& name, const std::string& filepath) {
            
        }

        bool ShaderLibrary::exists(const std::string& name) const {
            
        }

    }
}