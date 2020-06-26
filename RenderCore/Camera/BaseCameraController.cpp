#include "BaseCameraController.h"

namespace TRender {
    namespace Camera {
        BaseCamera& BaseCameraController::getCamera() {
            return m_Camera;
        }

        const BaseCamera& BaseCameraController::getCamera() const {
            return m_Camera;
        }
    }
}