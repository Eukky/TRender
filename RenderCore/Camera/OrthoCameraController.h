#ifndef _TRENDER_CAMERA_ORTHOCAMERACONTROLLER_H_
#define _TRENDER_CAMERA_ORTHOCAMERACONTROLLER_H_

#include "BaseCameraController.h"
#include "OrthoCamera.h"
namespace TRender
{
    namespace Camera
    {
        class OrthoCameraController : public BaseCameraController
        {
        public:
            OrthoCameraController(float aspectRatio, bool rotation);
            virtual ~OrthoCameraController() = default;

            virtual void onUpdate();
            virtual void onEvent(Event::Event &e);

            virtual float getZoomLevel();
            virtual void setZoomLevel(float zoomLevel);

            OrthoCamera &getCamera();

        private:
            virtual bool onMouseScroll(Event::MouseScrolledEvent &e);
            virtual bool onWindowResize(Event::WindowResizeEvent &e);

        private:
            OrthoCamera *m_Camera;
        };
    } // namespace Camera
} // namespace TRender

#endif //_TRENDER_CAMERA_ORTHOCAMERACONTROLLER_H_