#include "GLShader.h"
#include "Common/CommonHead.h"
#include <fstream>
#include <array>
#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>

namespace TRender {
    namespace Graphics {

        static GLenum ShaderTypeFromString(const std::string& type)
        {
            if (type == "vertex") {
                return GL_VERTEX_SHADER;
            }
            if (type == "fragment" || type == "pixel") {
                return GL_FRAGMENT_SHADER;
            }
            TR_CORE_ASSERT(false, "Unknown shader type!");
            return 0;
        }

        GLShader::GLShader(const std::string& filepath) {
            std::string source = readFile(filepath);
            auto shaderSources = preProcess(source);
            compile(shaderSources);

            // Extract name from filepath
            auto lastSlash = filepath.find_last_of("/\\");
            auto left = lastSlash == std::string::npos ? 0 : lastSlash + 1;
            auto lastDot = filepath.rfind('.');
            auto count = lastDot == std::string::npos ? filepath.size() - lastSlash : lastDot - lastSlash;
            m_Name = filepath.substr(left, count);
        }

        GLShader::GLShader(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc) 
            : m_Name(name) {
            std::unordered_map<GLenum, std::string> sources;
            sources[GL_VERTEX_SHADER] = vertexSrc;
            sources[GL_FRAGMENT_SHADER] = fragmentSrc;
            compile(sources);
        }

        GLShader::~GLShader() {
            glDeleteProgram(m_RenderID);
        }

        std::string GLShader::readFile(const std::string& filepath) {
            std::string result;
            std::ifstream in(filepath, std::ios::in | std::ios::binary);
            if (in) {
                in.seekg(0, std::ios::end);
                size_t size = in.tellg();
                if (size != -1) {
                    result.resize(size);
                    in.seekg(0, std::ios::beg);
                    in.read(&result[0], size);
                    in.close();
                } else {
                    TR_CORE_ERROR("Could not read from file '{0}'", filepath);
                }
            } else {
                TR_CORE_ERROR("Could not open file '{0}'", filepath);
            }

            return result;
        }
        std::unordered_map<GLenum, std::string> GLShader::preProcess(const std::string& source) {
            std::unordered_map<GLenum, std::string> shaderSources;

            const char* typeToken = "#type";
            size_t typeTokenLength = strlen(typeToken);
            size_t pos = source.find(typeToken, 0); //Start of shader type declaration line
            while (pos != std::string::npos)
            {
                size_t eol = source.find_first_of("\r\n", pos); //End of shader type declaration line
                TR_CORE_ASSERT(eol != std::string::npos, "Syntax error");
                size_t begin = pos + typeTokenLength + 1; //Start of shader type name (after "#type " keyword)
                std::string type = source.substr(begin, eol - begin);
                TR_CORE_ASSERT(ShaderTypeFromString(type), "Invalid shader type specified");

                size_t nextLinePos = source.find_first_not_of("\r\n", eol); //Start of shader code after shader type declaration line
                TR_CORE_ASSERT(nextLinePos != std::string::npos, "Syntax error");
                pos = source.find(typeToken, nextLinePos); //Start of next shader type declaration line

                shaderSources[ShaderTypeFromString(type)] = (pos == std::string::npos) ? source.substr(nextLinePos) : source.substr(nextLinePos, pos - nextLinePos);
            }
            return shaderSources;
        }

        void GLShader::compile(const std::unordered_map<GLenum, std::string>& shaderSources) {
            glewInit();
            GLuint program = glCreateProgram();
            TR_CORE_ASSERT(shaderSources.size() <= 2, "We only support 2 shaders for now");
            std::array<GLenum, 2> glShaderIDs;
            int glShaderIDIndex = 0;
            for (auto& kv : shaderSources) {
                GLenum type = kv.first;
                const std::string& source = kv.second;

                GLuint shader = glCreateShader(type);

                const GLchar* sourceCStr = source.c_str();
                glShaderSource(shader, 1, &sourceCStr, 0);

                glCompileShader(shader);

                GLint isCompiled = 0;
                glGetShaderiv(shader, GL_COMPILE_STATUS, &isCompiled);
                if (isCompiled == GL_FALSE)
                {
                    GLint maxLength = 0;
                    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

                    std::vector<GLchar> infoLog(maxLength);
                    glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

                    glDeleteShader(shader);

                    TR_CORE_ERROR("{0}", infoLog.data());
                    TR_CORE_ASSERT(false, "Shader compilation failure!");
                    break;
                }

                glAttachShader(program, shader);
                glShaderIDs[glShaderIDIndex++] = shader;
            }
            
            m_RenderID = program;

            // Link our program
            glLinkProgram(program);

            // Note the different functions here: glGetProgram* instead of glGetShader*.
            GLint isLinked = 0;
            glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
            if (isLinked == GL_FALSE)
            {
                GLint maxLength = 0;
                glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

                // The maxLength includes the NULL character
                std::vector<GLchar> infoLog(maxLength);
                glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

                // We don't need the program anymore.
                glDeleteProgram(program);
                
                for (auto id : glShaderIDs)
                    glDeleteShader(id);

                TR_CORE_ERROR("{0}", infoLog.data());
                TR_CORE_ASSERT(false, "Shader link failure!");
                return;
            }

            for (auto id : glShaderIDs)
            {
                glDetachShader(program, id);
                glDeleteShader(id);
            }
        }

        void GLShader::bind() const{
            glUseProgram(m_RenderID);
        }

        void GLShader::unbind() const{
            glUseProgram(0);
        }

        void GLShader::setInt(const std::string& name, int value) {
            GLint location = glGetUniformLocation(m_RenderID, name.c_str());
            glUniform1i(location, value);
        }

        void GLShader::setFloat(const std::string& name, float value) {
            GLint location = glGetUniformLocation(m_RenderID, name.c_str());
            glUniform1f(location, value);
        }

        void GLShader::setFloat(const std::string& name, const glm::vec1 value) {
            GLint location = glGetUniformLocation(m_RenderID, name.c_str());
            glUniform1f(location, value.x);
        }

        void GLShader::setFloat2(const std::string& name, const glm::vec2& value) {
            GLint location = glGetUniformLocation(m_RenderID, name.c_str());
            glUniform2f(location, value.x, value.y);
        }

        void GLShader::setFloat3(const std::string& name, const glm::vec3& value) {
            GLint location = glGetUniformLocation(m_RenderID, name.c_str());
            glUniform3f(location, value.x, value.y, value.z);
        }

        void GLShader::setFloat4(const std::string& name, const glm::vec4& value) {
            GLint location = glGetUniformLocation(m_RenderID, name.c_str());
            glUniform4f(location, value.x, value.y, value.z, value.w);
        }

        void GLShader::setMat2(const std::string& name, const glm::mat2& matrix) {
            GLint location = glGetUniformLocation(m_RenderID, name.c_str());
            glUniformMatrix2fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
        }

        void GLShader::setMat3(const std::string& name, const glm::mat3& matrix) {
            GLint location = glGetUniformLocation(m_RenderID, name.c_str());
            glUniformMatrix3fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
        }

        void GLShader::setMat4(const std::string& name, const glm::mat4& matrix) {
            GLint location = glGetUniformLocation(m_RenderID, name.c_str());
            glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
        }

        const std::string& GLShader::getName() const {
            return m_Name;
        }
    }
}