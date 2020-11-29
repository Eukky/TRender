#ifndef _TRENDER_CAMERA_ORTHOCAMERA_H_
#define _TRENDER_CAMERA_ORTHOCAMERA_H_

#include "BaseCamera.h"

namespace TRender
{
    namespace Camera
    {
        class OrthoCamera : public BaseCamera
        {
        public:
            OrthoCamera(float left, float right, float bottom, float top);

            virtual void setPosition(const glm::vec3 &position);
            virtual void setRotation(float rotation);
            virtual void setProjection(float left, float right, float bottom, float top);

        private:
            virtual void recalculateViewMatrix();
        };
    } // namespace Camera
} // namespace TRender

#endif //_TRENDER_CAMERA_ORTHOCAMERA_H_