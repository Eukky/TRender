#ifndef _TRENDER_CAMERA_BASECAMERACONTROLLER_H_
#define _TRENDER_CAMERA_BASECAMERACONTROLLER_H_

#include "BaseCamera.h"
#include "Event/EventHead.h"
#include <glm/glm.hpp>

namespace TRender {
    namespace Camera {
        class BaseCameraController {
        public:
            BaseCameraController() = default;
            virtual ~BaseCameraController() = default;

            virtual void onUpdate() = 0;
            virtual void onEvent(Event::Event& e) = 0;

            virtual float getZoomLevel() = 0;
            virtual void setZoomLevel(float zoomLevel) = 0;

        protected:
            virtual bool onMouseScroll(Event::MouseScrolledEvent& e) = 0;
            virtual bool onWindowResize(Event::WindowResizeEvent& e) = 0;
        protected:
            float m_AspectRatio;
            float m_ZoomLevel = 1.0f;
            bool m_Rotation;
            glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };
            float m_CameraRotation = 0.0f; 
            float m_CameraTranslationSpeed = 5.0f;
            float m_CameraRotationSpeed = 180.0f;
        };
    }
}
#endif //_TRENDER_CAMERA_BASECAMERACONTROLLER_H_