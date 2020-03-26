#include "CameraController.h"
#include "Common/CommonHead.h"
#include "Input.h"

namespace TRender {
    namespace Core {
        CameraController::CameraController(float aspectRatio, bool rotation = false) 
            : m_AspectRatio(aspectRatio), m_Rotation(rotation), m_Camera(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel) {

        }

        void CameraController::onUpdate() {
            if(Input::isKeyPressed(TR_KEY_A)) {
                m_CameraPosition.x -= cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed;
                m_CameraPosition.y -= sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed;
            } else if(Input::isKeyPressed(TR_KEY_D)) {
                m_CameraPosition.x += cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed;
                m_CameraPosition.y += sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed;
            } else if(Input::isKeyPressed(TR_KEY_W)) {
                m_CameraPosition.x += -sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed;
			    m_CameraPosition.y += cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed;
            } else if(Input::isKeyPressed(TR_KEY_S)) {
                m_CameraPosition.x -= -sin(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed;
			    m_CameraPosition.y -= cos(glm::radians(m_CameraRotation)) * m_CameraTranslationSpeed;
            }

            if(m_Rotation) {
                if (Input::isKeyPressed(TR_KEY_Q)) {
                    m_CameraRotation += m_CameraRotationSpeed;
                }
                if (Input::isKeyPressed(TR_KEY_E)) {
                    m_CameraRotation -= m_CameraRotationSpeed;
                }

                if (m_CameraRotation > 180.0f) {
                    m_CameraRotation -= 360.0f;
                } else if (m_CameraRotation <= -180.0f) {
                    m_CameraRotation += 360.0f;
                }
                m_Camera.setRotation(m_CameraRotation);
            }
            m_Camera.setPosition(m_CameraPosition);
            m_CameraTranslationSpeed = m_ZoomLevel;

        }

        void CameraController::onEvent(Event::Event& e) {
            Event::EventDispatcher dispatcher(e);
            dispatcher.dispatch<Event::MouseScrolledEvent>(std::bind(&CameraController::onMouseScrolled, this, std::placeholders::_1));
            dispatcher.dispatch<Event::WindowResizeEvent>(std::bind(&CameraController::onWindowResized, this, std::placeholders::_1));
        }

        Camera& CameraController::getCamera() {
            return m_Camera;
        }

        const Camera& CameraController::getCamera() const {
            return m_Camera;
        }

        float CameraController::getZoomLevel() {
            return m_ZoomLevel;
        }

        void CameraController::setZoomLevel(float zoomLevel) {
            m_ZoomLevel = zoomLevel;
        }

        bool CameraController::onMouseScrolled(Event::MouseScrolledEvent& e) {
            m_ZoomLevel -= e.getYOffset() * 0.25f;
            m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);
            m_Camera.setProjection(m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
            return false;
        }

        bool CameraController::onWindowResized(Event::WindowResizeEvent& e) {
            m_AspectRatio = (float)e.getWidth() / (float)e.getHeight();
            m_Camera.setProjection(-m_AspectRatio * m_ZoomLevel, m_AspectRatio * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel);
            return false;
        }
    }
}