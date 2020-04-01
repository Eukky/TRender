#ifndef _TRENDER_CAMERA_BASECAMERA_H_
#define _TRENDER_CAMERA_BASECAMERA_H_

#include <glm/glm.hpp>

namespace TRender {
    namespace Camera {
        class BaseCamera {
        public:
            BaseCamera(float left, float right, float bottom, float top);
            virtual ~BaseCamera();

            const glm::vec3& getPosition() const;
            glm::mat4& getViewProjectionMatrix() const;
            const glm::mat4& getProjectionMatrix() const;
            const glm::mat4& getViewMatrix() const;
            const float getRotation() const;

            virtual void setPosition(const glm::vec3& position);
            virtual void setRotation(float rotation);
            virtual void setProjection(float left, float right, float bottom, float top);

            
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

#endif //_TRENDER_CAMERA_BASECAMERA_H_