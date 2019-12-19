#ifndef _TRENDER_MATHS_VEC2_H_
#define _TRENDER_MATHS_VEC2_H_

#include "Common/Thead.h"


namespace TRender {
    namespace Maths {

        struct vec3;
        struct vec4;

        struct vec2 {
            float x, y;
            vec2();
            vec2(float x, float y);
            vec2(float scalar);

            vec2& add(const vec2& other);
            vec2& subtrace(const vec2&  other);
            vec2& multiply(const vec2& other);
            vec2& divide(const vec2& other);

            vec2& add(float value);
            vec2& subtrace(float value);
            vec2& multiply(float value);
            vec2& divide(float value);

            friend vec2 operator+(vec2 left, const vec2& right);
            friend vec2 operator-(vec2 left, const vec2& right);
            friend vec2 operator*(vec2 left, const vec2& right);
            friend vec2 operator/(vec2 left, const vec2& right);

            friend vec2 operator+(vec2 left, float value);
            friend vec2 operator-(vec2 left, float value);
            friend vec2 operator*(vec2 left, float value);
            friend vec2 operator/(vec2 left, float value);

            vec2& operator+=(const vec2& other);
            vec2& operator-=(const vec2& other);
            vec2& operator*=(const vec2& other);
            vec2& operator/=(const vec2& other);

            vec2& operator+=(float value);
            vec2& operator-=(float value);
            vec2& operator*=(float value);
            vec2& operator/=(float value);

            bool operator==(const vec2& other) const;
		    bool operator!=(const vec2& other) const;

            bool operator<(const vec2& other) const;
            bool operator<=(const vec2& other) const;
            bool operator>(const vec2& other) const;
            bool operator>=(const vec2& other) const;

            friend vec2 operator-(const vec2& vector);

            float distance(const vec2& other) const;
            float dot(const vec2& other) const;
            float magnitude() const;
            vec2 normalise() const;
            std::string toString() const;

            friend std::ostream& operator<<(std::ostream& stream, const vec2& vector);
        };
    }
}
#endif //_TRENDER_MATHS_VEC2_H_