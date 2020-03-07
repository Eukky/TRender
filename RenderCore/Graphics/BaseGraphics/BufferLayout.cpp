#include "BufferLayout.h"

namespace TRender {
    namespace Graphics {

        BufferLayout::BufferLayout() {

        }
        
        BufferLayout::BufferLayout(const std::initializer_list<BufferElement>& elements)
            : m_Elements(elements) {
            calculateOffsetAndStride();
        }

        uint32_t BufferLayout::getStride() const {
            return m_Stride;
        }

        const std::vector<BufferElement>& BufferLayout::getElements() const {
            return m_Elements;
        }

        std::vector<BufferElement>::iterator BufferLayout::begin() { 
            return m_Elements.begin(); 
        }

		std::vector<BufferElement>::iterator BufferLayout::end() { 
            return m_Elements.end(); 
        }

		std::vector<BufferElement>::const_iterator BufferLayout::begin() const { 
            return m_Elements.begin(); 
        }

		std::vector<BufferElement>::const_iterator BufferLayout::end() const { 
            return m_Elements.end(); 
        }

        void BufferLayout::calculateOffsetAndStride() {
            size_t offset = 0;
			m_Stride = 0;
			for (auto& element : m_Elements)
			{
				element.offset = offset;
				offset += element.size;
				m_Stride += element.size;
			}
        }
    }
}