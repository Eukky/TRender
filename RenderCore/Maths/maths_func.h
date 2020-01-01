#ifndef _TRENDER_MATHS_MATH_FUNC_H_
#define _TRENDER_MATHS_MATH_FUNC_H_

#include <math.h>

#define TR_PI 3.14159265358f

namespace TRender {
    namespace Maths
    {
        float toRadians(float degrees) {
            return (float)(degrees * TR_PI / 180.0f);
        }   
    }
    
}

#endif //_TRENDER_MATHS_MATH_FUNC_H_