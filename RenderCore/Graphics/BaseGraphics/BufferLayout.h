#ifndef _TRENDER_GRAPHICS_BUFFERLAYOUT_H_
#define _TRENDER_GRAPHICS_BUFFERLAYOUT_H_

#include "Common/CommonHead.h"
#include <vector>
namespace TRender {
    namespace Graphics {

        enum class ShaderDataType {
            None = 0,
            Float = 1,
            Float2 = 2,
            Float3 = 3,
            Float4 = 4,
            Mat3 = 5, 
            Mat4 = 6,
            Int = 7,
            Int2 = 8,
            Int3 = 9,
            Int4 = 10,
            Bool = 11
        };

        static uint32_t ShaderDataTypeSize(ShaderDataType type) {
            switch (type)
            {
                case ShaderDataType::Float:    return 4;
                case ShaderDataType::Float2:   return 4 * 2;
                case ShaderDataType::Float3:   return 4 * 3;
                case ShaderDataType::Float4:   return 4 * 4;
                case ShaderDataType::Mat3:     return 4 * 3 * 3;
                case ShaderDataType::Mat4:     return 4 * 4 * 4;
                case ShaderDataType::Int:      return 4;
                case ShaderDataType::Int2:     return 4 * 2;
                case ShaderDataType::Int3:     return 4 * 3;
                case ShaderDataType::Int4:     return 4 * 4;
                case ShaderDataType::Bool:     return 1;
            }
            TR_CORE_ASSERT(false, "Unknown ShaderDataType!");
            return 0;
        }

        struct BufferElement {
            std::string name;
            ShaderDataType type;
            uint32_t size;
            size_t offset;
            bool normalized;

            BufferElement() = default;

            BufferElement(ShaderDataType type, const std::string& name, bool normalized = false)
                : name(name), type(type), size(ShaderDataTypeSize(type)), offset(0), normalized(normalized) {

            }

            uint32_t getComponentCount() const {
                switch (type)
                {
                    case ShaderDataType::Float:   return 1;
                    case ShaderDataType::Float2:  return 2;
                    case ShaderDataType::Float3:  return 3;
                    case ShaderDataType::Float4:  return 4;
                    case ShaderDataType::Mat3:    return 3 * 3;
                    case ShaderDataType::Mat4:    return 4 * 4;
                    case ShaderDataType::Int:     return 1;
                    case ShaderDataType::Int2:    return 2;
                    case ShaderDataType::Int3:    return 3;
                    case ShaderDataType::Int4:    return 4;
                    case ShaderDataType::Bool:    return 1;
                }

                TR_CORE_ASSERT(false, "Unknown ShaderDataType!");
                return 0;
            }
        };

        class BufferLayout {
        public:
            BufferLayout();
            BufferLayout(const std::initializer_list<BufferElement>& elements);

            uint32_t getStride() const;
            const std::vector<BufferElement>& getElements() const;

            std::vector<BufferElement>::iterator begin();
            std::vector<BufferElement>::iterator end();
            std::vector<BufferElement>::const_iterator begin() const;
            std::vector<BufferElement>::const_iterator end() const;
        private:
            void calculateOffsetAndStride();
        private:
            std::vector<BufferElement> m_Elements;
            uint32_t m_Stride = 0;
        };
    }
}

#endif //_TRENDER_GRAPHICS_BUFFERLAYOUT_H_