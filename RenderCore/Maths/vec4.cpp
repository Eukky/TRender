#include "vec4.h"
#include "vec2.h"
#include "vec3.h"

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

        // vec4 vec4::multiply(const mat4& transform) const {
        //     return vec4(
        //         transform.rows[0].x * x + transform.rows[0].y * y + transform.rows[0].z * z + transform.rows[0].w * w,
        //         transform.rows[1].x * x + transform.rows[1].y * y + transform.rows[1].z * z + transform.rows[1].w * w,
        //         transform.rows[2].x * x + transform.rows[2].y * y + transform.rows[2].z * z + transform.rows[2].w * w,
        //         transform.rows[3].x * x + transform.rows[3].y * y + transform.rows[3].z * z + transform.rows[3].w * w
        //         );
        // }

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

        vec4 operator-(const vec4& vector) {
            return vec4(-vector.x, -vector.y, -vector.z, -vector.w);
        }

        float vec4::dot(const vec4& other) const {
		    return x * other.x + y * other.y + z * other.z + w * other.w;
	    }

        std::string vec4::toString() const {
            std::stringstream result;
            result << "vec4: (" << x << ", " << y << ", " << z << ", " << w << ")";
            return result.str();
        }

        std::ostream& operator<<(std::ostream& stream, const vec4& vector) {
            stream << vector.toString();
            return stream;
        }


    }
}