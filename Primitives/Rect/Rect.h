#pragma once

#include "Interface/RectFactory.h"

namespace game_engine {
namespace primitives {

template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
class Rect {
public:
    Rect(T x, T y, T width, T height) {
        m_impl = createRect(x, y, width, height);
    };

    bool findIntersection(const Rect<T>& rect) const { return m_impl->findIntersection(*(rect.m_impl.get())); };

private:
    std::shared_ptr<IRect<T>> m_impl;
};

}
}
