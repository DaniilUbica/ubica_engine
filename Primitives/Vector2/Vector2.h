#pragma once

#include "Interface/Vector2Factory.h"

#include <type_traits>

namespace game_engine {
namespace primitives {

template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
struct Vector2 {
    T x;
    T y;
};

}
}
