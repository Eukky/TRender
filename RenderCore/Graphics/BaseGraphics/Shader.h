#ifndef _TRENDER_GRAPHICS_SHADER_H_
#define _TRENDER_GRAPHICS_SHADER_H_

#include <string>

namespace TRender {
    namespace Graphics {
        class Shader {
        public:
            Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
            ~Shader();

            void bind();
            void unbind();
        };
    }
}

#endif //_TRENDER_GRAPHICS_SHADER_H_