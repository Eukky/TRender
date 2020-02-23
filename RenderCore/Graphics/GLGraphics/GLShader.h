#ifndef _TRENDER_GRAPHICS_GLSHADER_H_
#define _TRENDER_GRAPHICS_GLSHADER_H_

#include "Graphics/BaseGraphics/BaseShader.h"

#include <string>
namespace TRender {
    namespace Graphics {
        class GLShader : public BaseShader{
        public:
            GLShader(const std::string& filepath);
            GLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
            virtual ~GLShader();

            virtual void bind() const override;
            virtual void unbind() const override;
        };
    }
}
#endif //_TRENDER_GRAPHICS_GLSHADER_H_