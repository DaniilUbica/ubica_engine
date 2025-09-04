#pragma once

#ifdef USE_SFML
    #include "Impls/SFMLBased/Vector2/SFMLVector2.h"
#endif

#include <memory>

namespace game_engine {
namespace primitives {

static std::unique_ptr<IVector2> createVector() {
#ifdef USE_SFML
    return std::make_unique<SFMLVector2>();
#endif
    return nullptr;
}

}
}
