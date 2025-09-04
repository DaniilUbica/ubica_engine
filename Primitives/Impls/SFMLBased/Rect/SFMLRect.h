#pragma once

#include "Rect/Interface/IRect.h"

using namespace game_engine;
using namespace primitives;

template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
class SFMLRect: public IRect<T> {
public:
    SFMLRect(T x, T y, T width, T height) {};

    bool findIntersection(const IRect<T>& rect) const override {};
};
