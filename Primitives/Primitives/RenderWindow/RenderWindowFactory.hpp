#pragma once

#include "Config.h"
#include "IRenderWindow.h"

#include <memory>

#ifdef USE_SFML
    #include "Impls/SFMLBased/SFMLRenderWindow.hpp"
    #include "Impls/SFMLBased/Helpers.hpp"
#endif

namespace game_engine {
namespace primitives {

static std::unique_ptr<IRenderWindow> createRenderWindow(const Vector2u& windowSize, const std::string& title) {
#ifdef USE_SFML
    return std::make_unique<SFMLRenderWindow>(windowSize, title);
#endif
    return nullptr;
}

}
}
