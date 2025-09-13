#pragma once

#include "Texture/ITexture.h"

#include <SFML/Graphics.hpp>

namespace game_engine {
namespace primitives {

class SFMLTexture : public ITexture, public sf::Texture {
    
public:
    SFMLTexture() : sf::Texture() {};
    SFMLTexture(const std::string& path) : sf::Texture(path) {};
    
    bool loadFromFile(const std::string& path) override { return sf::Texture::loadFromFile(path); };
};

}
}
