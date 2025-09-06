#pragma once

#include "Config.h"

#include <memory>

#ifdef USE_SFML
    #include "Impls/SFMLBased/SFMLSprite.hpp"
#endif

namespace game_engine {
namespace primitives {

class Texture;

static std::unique_ptr<ISprite> createSprite(std::shared_ptr<ITexture> texture) {
#ifdef USE_SFML
    return std::make_unique<SFMLSprite>(texture);
#endif
    return nullptr;
}

}
}
