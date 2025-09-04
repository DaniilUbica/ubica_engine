#pragma once

#include <type_traits>

namespace game_engine {
namespace primitives {

template<typename T, typename = std::enable_if_t<std::is_arithmetic_v<T>>>
class IRect {
public:
    virtual ~IRect() {};
    virtual bool findIntersection(const IRect<T>& rect) const = 0;
};

}
}
