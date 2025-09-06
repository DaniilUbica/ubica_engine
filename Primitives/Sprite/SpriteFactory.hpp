#pragma once

#include "Config.h"

#include <memory>

#ifdef USE_SFML
    #include "Impls/SFMLBased/SFMLSprite.hpp"
#endif

namespace game_engine {
namespace primitives {

static std::unique_ptr<ISprite> createSprite() {
#ifdef USE_SFML
    return std::make_unique<SFMLSprite>();
#endif
    return nullptr;
}

}
}
