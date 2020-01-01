#ifndef _TRENDER_MATH_MAT4_H_
#define _TRENDER_MATH_MAT4_H_

#include <string>
#include <math.h>
#include <sstream>
#include "vec4.h"

namespace TRender {
    namespace Maths {

        struct vec2;
        struct vec3;
        struct vec4;

        struct mat4 {

            union {
                float elements[4 * 4];
                vec4 rows[4];
            };

            mat4();
            mat4(float diagonal);
            mat4(float* elements);
            mat4(const vec4& row0, const vec4& row1, const vec4& row2, const vec4& row3);

            static mat4 identity();

            mat4& multiply(const mat4& other);
            friend mat4 operator*(mat4 left, const mat4& right);
            mat4& operator*=(const mat4& other);

            vec3 multiply(const vec3& other) const;
            friend vec3 operator*(const mat4& left, const vec3& right);

            vec4 multiply(const vec4& other) const;
            friend vec4 operator*(const mat4& left, const vec4& right);

            mat4& invert();

            vec4 getColumn(int index) const;
            void setColumn(uint index, const vec4& column);
            vec3 getPosition() const;
            void setPosition(const vec3& position);

            static mat4 orthographic(float left, float right, float bottom, float top, float near, float far);
            static mat4 perspective(float fov, float aspectRatio, float near, float far);
            static mat4 lookAt(const vec3& camera, const vec3& object, const vec3& up);

            static mat4 translate(const vec3& translation);
            static mat4 rotate(float angle, const vec3& axis);
            // static mat4 Rotate(const Quaternion& quat);
            static mat4 scale(const vec3& scale);
            static mat4 invert(const mat4& matrix);

            static mat4 transpose(const mat4& matrix);

            std::string toString() const;
            friend std::ostream& operator<<(std::ostream& stream, const mat4& mat);
        };
       
        
    }
}


#endif // _TRENDER_MATH_MAT4_H_