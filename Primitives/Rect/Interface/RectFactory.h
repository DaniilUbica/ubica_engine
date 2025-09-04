#pragma once

#ifdef USE_SFML
    #include "Impls/SFMLBased/Rect/SFMLRect.h"
#endif

#include <memory>

namespace game_engine {
namespace primitives {

template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
static std::unique_ptr<IRect<T>> createRect(T x, T y, T width, T height) {
#ifdef USE_SFML
    return std::make_unique<SFMLRect<T>>(x, y, width, height);
#endif
    return nullptr;
}

}
}
