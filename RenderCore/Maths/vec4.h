#ifndef _TRENDER_MATHS_VEC4_H_
#define _TRENDER_MATHS_VEC4_H_

#include "Common/Thead.h"
#include "vec2.h"
#include "vec3.h"

namespace TRender {
     namespace Maths {

        struct vec2;
        struct vec3;
        struct mat4;
        
        struct vec4 {
            float x, y, z, w;

            vec4();
            vec4(float scalar);
            vec4(float x, float y, float z, float w);
            vec4(const vec2& xy, const vec2& zw);
            vec4(const vec3& xyz, float w);

            vec4& add(const vec4& other);
            vec4& subtract(const vec4& other);
            vec4& multiply(const vec4& other);
            vec4& divide(const vec4& other);

            vec4& add(float value);
            vec4& subtract(float value);
            vec4& multiply(float value);
            vec4& divide(float value);

            vec4 multiply(const mat4& transform) const;

            friend vec4 operator+(vec4 left, const vec4& right);
            friend vec4 operator-(vec4 left, const vec4& right);
            friend vec4 operator*(vec4 left, const vec4& right);
            friend vec4 operator/(vec4 left, const vec4& right);

            friend vec4 operator+(vec4 left, float right);
            friend vec4 operator-(vec4 left, float right);
            friend vec4 operator*(vec4 left, float right);
            friend vec4 operator/(vec4 left, float right);

            vec4& operator+=(const vec4& other);
            vec4& operator-=(const vec4& other);
            vec4& operator*=(const vec4& other);
            vec4& operator/=(const vec4& other);

            vec4& operator+=(float other);
            vec4& operator-=(float other);
            vec4& operator*=(float other);
            vec4& operator/=(float other);

            bool operator==(const vec4& other);
            bool operator!=(const vec4& other);

            friend vec4 operator-(const vec4& vector);

            float dot(const vec4& other) const;

            std::string toString() const;

            friend std::ostream& operator<<(std::ostream& stream, const vec4& vector);
        };
    }
}

#endif //_TRENDER_MATHS_VEC4_H_