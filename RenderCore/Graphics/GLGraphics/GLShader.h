#ifndef _TRENDER_GRAPHICS_GLSHADER_H_
#define _TRENDER_GRAPHICS_GLSHADER_H_

#include "Graphics/BaseGraphics/BaseShader.h"
#include <string>
#include <unordered_map>

typedef unsigned int GLenum;

namespace TRender {
    namespace Graphics {
        class GLShader : public BaseShader{
        public:
            GLShader(const std::string& filepath);
            GLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
            virtual ~GLShader();

            virtual void bind() const override;
            virtual void unbind() const override;

            virtual void setInt(const std::string& name, int value) override;
            virtual void setFloat(const std::string& name, float value) override;
            virtual void setFloat(const std::string& name, const glm::vec1 value) override;
            virtual void setFloat2(const std::string& name, const glm::vec2& value) override;
            virtual void setFloat3(const std::string& name, const glm::vec3& value) override;
            virtual void setFloat4(const std::string& name, const glm::vec4& value) override;
            virtual void setMat2(const std::string& name, const glm::mat2& matrix) override;
            virtual void setMat3(const std::string& name, const glm::mat3& matrix) override;
            virtual void setMat4(const std::string& name, const glm::mat4& matrix) override;

            virtual const std::string& getName() const override;
        private:
            std::string readFile(const std::string& filepath);
            std::unordered_map<GLenum, std::string> preProcess(const std::string& source);
            void compile(const std::unordered_map<GLenum, std::string>& shaderSource);
        private:
            uint32_t m_RenderID;
            std::string m_Name;
        };
    }
}
#endif //_TRENDER_GRAPHICS_GLSHADER_H_