#pragma once

//#ifdef USE_SFML
    #include "Impls/SFMLBased/Sprite/SFMLSprite.h"
//#endif

#include <memory>

namespace game_engine {
namespace primitives {

static std::unique_ptr<ISprite> createSprite() {
#ifdef USE_SFML
    return std::make_unique<SFMLSprite>();
#endif
}

}
}
