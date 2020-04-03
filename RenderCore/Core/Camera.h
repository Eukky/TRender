#ifndef _TRNEDER_CORE_CAMERA_H_
#define _TRNEDER_CORE_CAMERA_H_

#include <glm/glm.hpp>

namespace TRender {
    namespace Core {
        class Camera {
        public:
            Camera(float left, float right, float bottom, float top);

            const glm::vec3& getPosition() const;
            void setPosition(const glm::vec3& position);

            const float getRotation() const;
            void setRotation(float rotation);

            const glm::mat4& getViewProjectionMatrix() const;
            void setProjection(float left, float right, float bottom, float top);

            const glm::mat4& getProjectionMatrix() const;
            const glm::mat4& getViewMatrix() const;
            
        private:
            void recalculateViewMatrix();
        private:
            glm::mat4 m_ProjectionMatrix;
            glm::mat4 m_ViewMatrix;
            glm::mat4 m_ViewProjectionMatrix;

            glm::vec3 m_Position = { 0.0f, 0.0f, 0.0f };
            float m_Rotation = 0.0f;
        };
    }
}
#endif //_TRNEDER_CORE_CAMERA_H_