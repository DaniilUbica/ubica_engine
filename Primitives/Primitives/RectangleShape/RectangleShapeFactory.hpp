#pragma once

#include "Config.h"
#include "IRectangleShape.h"

#include <memory>

#ifdef USE_SFML
    #include "Impls/SFMLBased/SFMLRectangleShape.hpp"
#endif

namespace game_engine {
namespace primitives {

static std::shared_ptr<IRectangleShape> createRectangleShape() {
#ifdef USE_SFML
    return std::make_shared<SFMLRectangleShape>();
#endif
    return nullptr;
}

}
}
