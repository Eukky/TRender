#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

namespace TRender {
    namespace Core {
        Camera::Camera(float left, float right, float bottom, float top) {
            m_ProjectionMatrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
            m_ViewMatrix = glm::mat4(1.0f);
            m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
        }

        const glm::vec3& Camera::getPosition() const {
            return m_Position;
        }

        void Camera::setPosition(const glm::vec3& position) {
            m_Position = position;
        }

        const float Camera::getRotation() const {
            return m_Rotation;
        }

        void Camera::setRotation(float rotation) {
            m_Rotation = rotation;
        }

        const glm::mat4& Camera::getViewProjectionMatrix() const {
            return m_ViewProjectionMatrix;
        }

        void Camera::setProjection(float left, float right, float bottom, float top) {
            m_ProjectionMatrix = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
            m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
        }

        const glm::mat4& Camera::getProjectionMatrix() const {
            return m_ProjectionMatrix;
        }

        const glm::mat4& Camera::getViewMatrix() const {
            return m_ViewMatrix;
        }

        void Camera::recalculateViewMatrix() {
            glm::mat4 transform = glm::translate(glm::mat4(1.0f), m_Position) * glm::rotate(glm::mat4(1.0f), 
                                                 glm::radians(m_Rotation), 
                                                 glm::vec3(0.0f, 0.0f, 1.0f));
            m_ViewMatrix = glm::inverse(transform);
		    m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
        }
    }
}