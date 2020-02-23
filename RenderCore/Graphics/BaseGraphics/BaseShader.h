#ifndef _TRENDER_GRAPHICS_BASICSHADER_H_
#define _TRENDER_GRAPHICS_BASICSHADER_H_

#include <string>
#include <memory>

namespace TRender {
    namespace Graphics {
        class BaseShader {
        public:
            virtual ~BaseShader() = default;

            virtual void bind() const = 0;
            virtual void unbind() const = 0;

            virtual const std::string& getName() const = 0;

            static std::shared_ptr<BaseShader> create(const std::string& filepath);
            static std::shared_ptr<BaseShader> create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
        };
    }
}

#endif //_TRENDER_GRAPHICS_BASICSHADER_H_