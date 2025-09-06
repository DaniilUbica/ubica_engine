#pragma once

#include "Config.h"

#include <memory>

#ifdef USE_SFML
    #include "Impls/SFMLBased/SFMLTexture.hpp"
#endif

namespace game_engine {
namespace primitives {

static std::unique_ptr<ITexture> createTexture() {
#ifdef USE_SFML
    return std::make_unique<SFMLTexture>();
#endif
    return nullptr;
}

}
}
