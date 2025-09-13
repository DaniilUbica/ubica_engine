#pragma once

#include <type_traits>

namespace game_engine {
namespace primitives {

template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
struct Vector2 {
    T x;
    T y;

    Vector2() {};
    Vector2(T x, T y) : x(x), y(y) {};

    Vector2& operator=(const Vector2& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
        }

        return *this;
    }

    Vector2 operator+(const Vector2& other) const {
        return {x + other.x, y + other.y};
    }

    Vector2 operator-(const Vector2& other) const {
        return {x - other.x, y - other.y};
    }

    Vector2& operator+=(const Vector2& other) {
        x += other.x;
        y += other.y;

        return *this;
    }

    Vector2& operator-=(const Vector2& other) {
        x -= other.x;
        y -= other.y;

        return *this;
    }

    Vector2 operator*(const Vector2& other) const {
        return {x * other.x, y * other.y};
    }

    Vector2 operator/(const Vector2& other) const {
        return {x / other.x, y / other.y};
    }

    Vector2& operator*=(const Vector2& other) {
        x *= other.x;
        y *= other.y;

        return *this;
    }

    Vector2& operator/=(const Vector2& other) {
        x /= other.x;
        y /= other.y;

        return *this;
    }
};

using Vector2f = Vector2<float>;
using Vector2i = Vector2<int>;
using Vector2u = Vector2<unsigned int>;

template<typename T>
Vector2<T> operator+(const Vector2<T>& vec, T scalar) {
    return {vec.x + scalar, vec.y + scalar};
}

template<typename T>
Vector2<T> operator-(const Vector2<T>& vec, T scalar) {
    return {vec.x - scalar, vec.y - scalar};
}

template<typename T>
Vector2<T>& operator+=(Vector2<T>& vec, T scalar) {
    vec.x += scalar;
    vec.y += scalar;

    return vec;
}

template<typename T>
Vector2<T>& operator-=(Vector2<T>& vec, T scalar) {
    vec.x -= scalar;
    vec.y -= scalar;

    return vec;
}

template<typename T>
Vector2<T> operator*(const Vector2<T>& vec, T scalar) {
    return {vec.x * scalar, vec.y * scalar};
}

template<typename T>
Vector2<T> operator/(const Vector2<T>& vec, T scalar) {
    return {vec.x / scalar, vec.y / scalar};
}

template<typename T>
Vector2<T>& operator*=(Vector2<T>& vec, T scalar) {
    vec.x *= scalar;
    vec.y *= scalar;

    return vec;
}

template<typename T>
Vector2<T>& operator/=(Vector2<T>& vec, T scalar) {
    vec.x /= scalar;
    vec.y /= scalar;

    return vec;
}

}
}
