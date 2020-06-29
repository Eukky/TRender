#include "OrthoCamera.h"
#include <glm/gtc/matrix_transform.hpp>

namespace TRender {
    namespace Camera {
        OrthoCamera::OrthoCamera(float left, float right, float bottom, float top) {
            m_ProjectionMatrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
            m_ViewMatrix = glm::mat4(1.0f);
            m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
        }

        void OrthoCamera::setPosition(const glm::vec3& position) {
            m_Position = position;
            recalculateViewMatrix();
        }

        void OrthoCamera::setRotation(float rotation) {
            m_Rotation = rotation;
            recalculateViewMatrix();
        }

        void OrthoCamera::setProjection(float left, float right, float bottom, float top) {
            m_ProjectionMatrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
            m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
        }

        void OrthoCamera::recalculateViewMatrix() {
            glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_Position) * glm::rotate(glm::mat4(1.0f), 
                                                 glm::radians(m_Rotation), 
                                                 glm::vec3(0.0f, 0.0f, 1.0f));
            m_ViewMatrix = glm::inverse(transform);
		    m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
        }
 
    }
}