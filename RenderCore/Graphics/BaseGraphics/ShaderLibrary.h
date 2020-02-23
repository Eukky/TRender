#ifndef _TRENDER_GRAPHICS_SHADERLIBRARY_H_
#define _TRENDER_GRAPHICS_SHADERLIBRARY_H_

#include "BaseShader.h"
#include <unordered_map>

namespace TRender {
    namespace Graphics {
        class ShaderLibrary {
        public:
            void add(const std::string& name, const std::shared_ptr<BaseShader>& shader);
            void add(const std::shared_ptr<BaseShader>& shader);
            std::shared_ptr<BaseShader> load(const std::string& filepath);
            std::shared_ptr<BaseShader> load(const std::string& name, const std::string& filepath);
            std::shared_ptr<BaseShader> get(const std::string& name);

            bool exists(const std::string& name) const;
        private:
            std::unordered_map<std::string, std::shared_ptr<BaseShader>> m_Shader;
        };
    }
}

#endif //_TRENDER_GRAPHICS_SHADERLIBRARY_H_