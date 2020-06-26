#ifndef _TRENDER_CAMERA_BASECAMERACONTROLLER_H_
#define _TRENDER_CAMERA_BASECAMERACONTROLLER_H_

#include "BaseCamera.h"
#include "Event/EventHead.h"
#include <glm/glm.hpp>

namespace TRender {
    namespace Camera {
        class BaseCameraController {
        public:
            BaseCameraController();
            virtual ~BaseCameraController();

            virtual void onUpdate();
            virtual void onEvent();

            BaseCamera& getCamera();
            const BaseCamera& getCamera() const;

            virtual float getZoomLevel();
            virtual float setZoomLevel();

        private:
            virtual bool onMouseScroll(Event::MouseScrolledEvent& e);
            virtual bool onWindowResize(Event::WindowResizeEvent& e);
        private:
            float m_AspectRatio;
            float m_ZoomLevel = 1.0f;
            BaseCamera m_Camera;
            bool m_Rotation;
            glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };
            float m_CameraRotation = 0.0f; 
            float m_CameraTranslationSpeed = 5.0f;
            float m_CameraRotationSpeed = 180.0f;
        };
    }
}
#endif //_TRENDER_CAMERA_BASECAMERACONTROLLER_H_