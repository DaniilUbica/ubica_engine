#pragma once

#include "Config.h"
#include "IImage.h"

#include <memory>

#ifdef USE_SFML
    #include "Impls/SFMLBased/SFMLImage.hpp"
#endif

namespace game_engine {
namespace primitives {

static std::shared_ptr<IImage> createImage() {
#ifdef USE_SFML
    return std::make_shared<SFMLImage>();
#endif
    return nullptr;
}

}
}
