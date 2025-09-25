#pragma once

#include "Config.h"
#include "IText.h"

#include <memory>

#ifdef USE_SFML
    #include "Impls/SFMLBased/SFMLText.hpp"
#endif

namespace game_engine {
namespace primitives {

static std::shared_ptr<IText> createText(std::shared_ptr<IFont> font) {
#ifdef USE_SFML
    return std::make_shared<SFMLText>(font);
#endif
    return nullptr;
}

}
}
