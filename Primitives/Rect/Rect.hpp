#pragma once

#include "RectFactory.hpp"
#include "Vector2.hpp"

namespace game_engine {
namespace primitives {

template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
class Rect {
public:
    Rect(T x, T y, T width, T height) { m_impl = createRect(x, y, width, height); };
    Rect(const Vector2<T>& pos, const Vector2<T>& size) { m_impl = createRect(pos.x, pos.y, size.x, size.y); };

    bool intersects(const Rect<T>& rect) const { return m_impl->intersects(*(rect.m_impl.get())); };
    Vector2<T> getPosition() const { return m_impl->getPosition(); };
    Vector2<T> getSize() const { return m_impl->getSize(); };

private:
    std::shared_ptr<IRect<T>> m_impl;
};

}
}
