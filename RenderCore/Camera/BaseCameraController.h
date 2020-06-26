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

            
        };
    }
}
#endif //_TRENDER_CAMERA_BASECAMERACONTROLLER_H_