#ifndef _TRENDER_MATHS_VEC2_H_
#define _TRENDER_MATHS_VEC2_H_

namespace TRender {
    namespace Maths {
        struct vec2 {
            float x, y;
            vec2();
            vec2(float x, float y);
            vec2(float scalar);
        };
    }
}
#endif //_TRENDER_MATHS_VEC2_H_