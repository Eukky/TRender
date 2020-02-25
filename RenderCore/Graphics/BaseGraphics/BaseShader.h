#ifndef _TRENDER_GRAPHICS_BASICSHADER_H_
#define _TRENDER_GRAPHICS_BASICSHADER_H_

#include <string>
#include <memory>
#include <glm/glm.hpp>

namespace TRender {
    namespace Graphics {
        class BaseShader {
        public:
            virtual ~BaseShader() = default;

            virtual void bind() const = 0;
            virtual void unbind() const = 0;

            virtual void setInt(const std::string& name, int value) = 0;
            virtual void setFloat(const std::string& name, float value) = 0;
            virtual void setFloat(const std::string& name, const glm::vec1 value) = 0;
            virtual void setFloat2(const std::string& name, const glm::vec2& value) = 0;
            virtual void setFloat3(const std::string& name, const glm::vec3& value) = 0;
            virtual void setFloat4(const std::string& name, const glm::vec4& value) = 0;
            virtual void setMat2(const std::string& name, const glm::mat2& value) = 0;
            virtual void setMat3(const std::string& name, const glm::mat3& value) = 0;
            virtual void setMat4(const std::string& name, const glm::mat4& value) = 0;

            virtual const std::string& getName() const = 0;

            static std::shared_ptr<BaseShader> create(const std::string& filepath);
            static std::shared_ptr<BaseShader> create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
        };
    }
}

#endif //_TRENDER_GRAPHICS_BASICSHADER_H_