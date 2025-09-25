#pragma once

#include "Config.h"
#include "IFont.h"

#include <memory>

#ifdef USE_SFML
    #include "Impls/SFMLBased/SFMLFont.hpp"
#endif

namespace game_engine {
namespace primitives {

static std::shared_ptr<IFont> createFont() {
#ifdef USE_SFML
    return std::make_shared<SFMLFont>();
#endif
    return nullptr;
}

}
}
