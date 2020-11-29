#include "BaseCamera.h"
#include <glm/gtc/matrix_transform.hpp>

namespace TRender
{
    namespace Camera
    {
        const glm::vec3 &BaseCamera::getPosition() const
        {
            return m_Position;
        }

        const glm::mat4 &BaseCamera::getViewProjectionMatrix() const
        {
            return m_ViewProjectionMatrix;
        }

        const glm::mat4 &BaseCamera::getProjectionMatrix() const
        {
            return m_ProjectionMatrix;
        }

        const glm::mat4 &BaseCamera::getViewMatrix() const
        {
            return m_ViewMatrix;
        }

        const float BaseCamera::getRotation() const
        {
            return m_Rotation;
        }
    } // namespace Camera
} // namespace TRender