#ifndef _TRENDER_CORE_CAMERACONTROLLER_H_
#define _TRENDER_CORE_CAMERACONTROLLER_H_

#include "Event/EventHead.h"
#include "Camera.h"
#include <glm/glm.hpp>

namespace TRender {
    namespace Core {
        class CameraController {
        public: 
            CameraController(float aspectRatio, bool rotation = false);

            void onUpdate();
            void onEvent(Event::Event& e);

            Camera& getCamera();
            const Camera& getCamera() const;

            float getZoomLevel();
            void setZoomLevel(float zoomLevel);

        private:
            bool onMouseScroll(Event::MouseScrolledEvent& e);
            bool onWindowResize(Event::WindowResizeEvent& e);
        private:
            float m_AspectRatio;
            float m_ZoomLevel = 1.0f;
            Camera m_Camera;

            bool m_Rotation;
            glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };
            float m_CameraRotation = 0.0f; 
            float m_CameraTranslationSpeed = 5.0f;
            float m_CameraRotationSpeed = 180.0f;
        };
    }
}

#endif //_TRENDER_CORE_CAMERACONTROLLER_H_