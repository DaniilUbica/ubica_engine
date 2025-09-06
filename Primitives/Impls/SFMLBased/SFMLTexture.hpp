#pragma once

#include "Texture/ITexture.h"

#include <SFML/Graphics.hpp>

namespace game_engine {
namespace primitives {

class SFMLTexture : public ITexture {
    friend class SFMLSprite;
    
public:
    SFMLTexture() : m_sfTexture() {};
    SFMLTexture(const std::string& path) : m_sfTexture(path) {};
    
    bool loadFromFile(const std::string& path) override { return m_sfTexture.loadFromFile(path); };
    
private:
    sf::Texture m_sfTexture;
};

}
}
