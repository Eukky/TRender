#include "OrthoCameraController.h"
#include "Core/Input.h"
#include "Common/CommonHead.h"

namespace TRender {
    namespace Camera {
        OrthoCameraController::OrthoCameraController(float aspectRatio, bool rotation) {
            m_AspectRatio = aspectRatio;
            m_Rotation = rotation;
            m_Camera = new OrthoCamera(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
        }

        void OrthoCameraController::onUpdate() {
            if(Core::Input::isKeyPressed(TR_KEY_A)) {
                m_CameraPosition.x -= cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * 0.005f;
                m_CameraPosition.y -= sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * 0.005f;
            } else if(Core::Input::isKeyPressed(TR_KEY_D)) {
                m_CameraPosition.x += cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * 0.005f;
                m_CameraPosition.y += sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * 0.005f;
            } else if(Core::Input::isKeyPressed(TR_KEY_W)) {
                m_CameraPosition.x += -sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * 0.005f;
			    m_CameraPosition.y += cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * 0.005f;
            } else if(Core::Input::isKeyPressed(TR_KEY_S)) {
                m_CameraPosition.x -= -sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * 0.005f;
			    m_CameraPosition.y -= cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed * 0.005f;
            }

            if(m_Rotation) {
                if (Core::Input::isKeyPressed(TR_KEY_Q)) {
                    m_CameraRotation += m_CameraRotationSpeed * 0.05;
                }
                if (Core::Input::isKeyPressed(TR_KEY_E)) {
                    m_CameraRotation -= m_CameraRotationSpeed * 0.05;
                }

                if (m_CameraRotation > 180.0f) {
                    m_CameraRotation -= 360.0f;
                } else if (m_CameraRotation <= -180.0f) {
                    m_CameraRotation += 360.0f;
                }
                m_Camera->setRotation(m_CameraRotation);
            }
            m_Camera->setPosition(m_CameraPosition);
            m_CameraTranslationSpeed = m_ZoomLevel;
        }

        void OrthoCameraController::onEvent(Event::Event& e) {
            Event::EventDispatcher dispatcher(e);
            dispatcher.dispatch<Event::MouseScrolledEvent>(std::bind(&OrthoCameraController::onMouseScroll, this, std::placeholders::_1));
            dispatcher.dispatch<Event::WindowResizeEvent>(std::bind(&OrthoCameraController::onWindowResize, this, std::placeholders::_1));
        }

        float OrthoCameraController::getZoomLevel() {
            return m_ZoomLevel;
        }

        void OrthoCameraController::setZoomLevel(float zoomLevel) {
            m_ZoomLevel = zoomLevel;
        }

        bool OrthoCameraController::onMouseScroll(Event::MouseScrolledEvent& e) {
            m_ZoomLevel -= e.getYOffset() * 0.25f * 0.005f;
            m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
            m_Camera->setProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
            return false;
        }

        bool OrthoCameraController::onWindowResize(Event::WindowResizeEvent& e) {
            m_AspectRatio = (float)e.getWidth() / (float)e.getHeight();
            m_Camera->setProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
            return false;
        }

        OrthoCamera& OrthoCameraController::getCamera() {
            return *m_Camera;
        }
    }
}