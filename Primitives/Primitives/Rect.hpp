#pragma once

#include "Vector2.hpp"

namespace game_engine {
namespace primitives {

template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
class Rect {
public:
    Rect(T x, T y, T width, T height) : m_pos({x, y}), m_size({width, height}) {};
    Rect(const Vector2<T>& pos, const Vector2<T>& size) : m_pos(pos), m_size(size) {};

    bool intersects(const Rect<T>& rect) const {
        const auto min = [](T a, T b) { return (a < b) ? a : b; };
        const auto max = [](T a, T b) { return (a < b) ? b : a; };

        const T r1MinX = min(m_pos.x, static_cast<T>(m_pos.x + m_size.x));
        const T r1MaxX = max(m_pos.x, static_cast<T>(m_pos.x + m_size.x));
        const T r1MinY = min(m_pos.y, static_cast<T>(m_pos.y + m_size.y));
        const T r1MaxY = max(m_pos.y, static_cast<T>(m_pos.y + m_size.y));

        const T r2MinX = min(rect.m_pos.x, static_cast<T>(rect.m_pos.x + rect.m_size.x));
        const T r2MaxX = max(rect.m_pos.x, static_cast<T>(rect.m_pos.x + rect.m_size.x));
        const T r2MinY = min(rect.m_pos.y, static_cast<T>(rect.m_pos.y + rect.m_size.y));
        const T r2MaxY = max(rect.m_pos.y, static_cast<T>(rect.m_pos.y + rect.m_size.y));

        const T interLeft   = max(r1MinX, r2MinX);
        const T interTop    = max(r1MinY, r2MinY);
        const T interRight  = min(r1MaxX, r2MaxX);
        const T interBottom = min(r1MaxY, r2MaxY);

        if ((interLeft < interRight) && (interTop < interBottom)) {
            return true;
        }

        return false;
    };
    
    Vector2<T> getPosition() const { return m_pos; };
    Vector2<T> getSize() const { return m_size; };

private:
    Vector2<T> m_pos;
    Vector2<T> m_size;
};

using FloatRect = Rect<float>;
using IntRect = Rect<int>;

}
}
