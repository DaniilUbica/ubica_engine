#pragma once

#include "Rect/IRect.h"

#include <SFML/Graphics.hpp>

namespace game_engine {
namespace primitives {

template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
class SFMLRect: public IRect<T> {
public:
    SFMLRect(T x, T y, T width, T height) {
        m_sfRect = { { x, y }, { width, height } };
    }
    
    bool intersects(const IRect<T>& rect) const override {
        const auto sfRectImpl = dynamic_cast<const SFMLRect<T>&>(rect);
        return m_sfRect.findIntersection(sfRectImpl.m_sfRect) != std::nullopt;
    }
    
    Vector2<T> getPosition() const override { return { m_sfRect.position.x, m_sfRect.position.y }; };
    Vector2<T> getSize() const override { return { m_sfRect.size.x, m_sfRect.size.y }; };
    
private:
    sf::Rect<T> m_sfRect;
};

}
}
