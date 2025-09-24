#pragma once

#include "Config.h"
#include "ITexture.h"

#include <memory>

#ifdef USE_SFML
    #include "Impls/SFMLBased/SFMLTexture.hpp"
#endif

namespace game_engine {
namespace primitives {

static std::shared_ptr<ITexture> createTexture() {
#ifdef USE_SFML
    return std::make_shared<SFMLTexture>();
#endif
    return nullptr;
}

}
}
