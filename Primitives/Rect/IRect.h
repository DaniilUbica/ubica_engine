#pragma once

#include "Vector2.hpp"

namespace game_engine {
namespace primitives {

template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
class IRect {
public:
    virtual ~IRect() {};

    virtual bool intersects(const IRect<T>& rect) const = 0;

    virtual Vector2<T> getPosition() const = 0;
    virtual Vector2<T> getSize() const = 0;
};

}
}
