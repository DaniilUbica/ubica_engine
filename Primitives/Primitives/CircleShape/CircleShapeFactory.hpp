#pragma once

#include "Config.h"
#include "ICircleShape.h"

#include <memory>

#ifdef USE_SFML
    #include "Impls/SFMLBased/SFMLCircleShape.hpp"
#endif

namespace game_engine {
namespace primitives {

static std::shared_ptr<ICircleShape> createCircleShape() {
#ifdef USE_SFML
    return std::make_shared<SFMLCircleShape>();
#endif
    return nullptr;
}

}
}
