#pragma once

#include "Rect/Interface/IRect.h"

#include <SFML/Graphics.hpp>

using namespace game_engine;
using namespace primitives;

template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
class SFMLRect: public IRect<T> {
public:
    SFMLRect(T x, T y, T width, T height) {
        m_sfRect = { { x, y }, { width, height } };
    }

    bool findIntersection(const IRect<T>& rect) const override {
        const auto sfRectImpl = dynamic_cast<const SFMLRect<T>&>(rect);
        return m_sfRect.findIntersection(sfRectImpl.m_sfRect) != std::nullopt;
    }

private:
    sf::Rect<T> m_sfRect;
};
