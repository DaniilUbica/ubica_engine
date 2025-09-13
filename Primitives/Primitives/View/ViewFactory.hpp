#pragma once

#include "Config.h"
#include "IView.h"
#include "Rect.hpp"

#include <memory>

#ifdef USE_SFML
    #include "Impls/SFMLBased/SFMLView.hpp"
#endif

namespace game_engine {
namespace primitives {

static std::shared_ptr<IView> createView(const FloatRect& viewRect) {
#ifdef USE_SFML
    return std::make_shared<SFMLView>(viewRect);
#endif
    return nullptr;
}

}
}
