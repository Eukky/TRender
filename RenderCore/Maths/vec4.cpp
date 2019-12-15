#include "vec4.h"

namespace TRender {
    namespace Maths {
        vec4::vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}

        vec4::vec4(float scalar) : x(scalar), y(scalar), z(scalar), w(scalar) {}

        vec4::vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

        vec4::vec4(const vec2& xy, const vec2& zw) : x(xy.x), y(xy.y), z(zw.x), w(zw.y) {}

        vec4::vec4(const vec3& xyz, float w) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) {}

        vec4& vec4::add(const vec4& other) {
            x += other.x;
            y += other.y;
            z += other.z;
            w += other.w;

            return *this;
        }

        vec4& vec4::subtract(const vec4& other) {
            x -= other.x;
            y -= other.y;
            z -= other.z;
            w -= other.w;

            return *this;
        }

        vec4& vec4::multiply(const vec4& other) {
            x *= other.x;
            y *= other.y;
            z *= other.z;
            w *= other.w;

            return *this;
        }

        vec4& vec4::divide(const vec4& other) {
            x /= other.x;
            y /= other.y;
            z /= other.z;
            w /= other.w;

            return *this;
        }

        vec4& vec4::add(float value) {
            x += value;
            y += value;
            z += value;
            w += value;

            return *this;
        }

        vec4& vec4::subtract(float value) {
            x -= value;
            y -= value;
            z -= value;
            w -= value;

            return *this;
        }

        vec4& vec4::multiply(float value) {
            x *= value;
            y *= value;
            z *= value;
            w *= value;

            return *this;
        }

        vec4& vec4::divide(float value) {
            x /= value;
            y /= value;
            z /= value;
            w /= value;

            return *this;
        }

        vec4 operator+(vec4 left, const vec4& right) {
            return left.add(right);
        }

        vec4 operator-(vec4 left, const vec4& right) {
            return left.subtract(right);
        }

        vec4 operator*(vec4 left, const vec4& right) {
            return left.multiply(right);
        }

        vec4 operator/(vec4 left, const vec4& right) {
            return left.divide(right);
        }

        vec4 operator+(vec4 left, float right) {
            return left.add(right);
        }

        vec4 operator-(vec4 left, float right) {
            return left.subtract(right);
        }

        vec4 operator*(vec4 left, float right) {
            return left.multiply(right);
        }

        vec4 operator/(vec4 left, float right) {
            return left.divide(right);
        }

        vec4& vec4::operator+=(const vec4& other) {
            return add(other);
        }

        vec4& vec4::operator-=(const vec4& other) {
            return subtract(other);
        }

        vec4& vec4::operator*=(const vec4& other) {
            return multiply(other);
        }

        vec4& vec4::operator/=(const vec4& other) {
            return divide(other);
        }

        vec4& vec4::operator+=(float other) {
            return add(other);
        }

        vec4& vec4::operator-=(float other) {
            return subtract(other);
        }

        vec4& vec4::operator*=(float other) {
            return multiply(other);
        }

        vec4& vec4::operator/=(float other) {
            return divide(other);
        }

        bool vec4::operator==(const vec4& other) {
            return x == other.x && y == other.y && z == other.z && w == other.w;
        }

        bool vec4::operator!=(const vec4& other) {
            return !(*this == other);
        }


    }
}