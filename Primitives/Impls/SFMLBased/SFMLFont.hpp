#pragma once

#include "Font/IFont.h"

#include <SFML/Graphics.hpp>

namespace game_engine {
namespace primitives {

class SFMLFont : public IFont, public sf::Font {

public:
    SFMLFont() : sf::Font() {};

    bool loadFromFile(const std::string& path) { return sf::Font::openFromFile(path); };
};

}
}
