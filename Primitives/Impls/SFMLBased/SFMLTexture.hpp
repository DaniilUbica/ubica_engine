#pragma once

#include "Texture/ITexture.h"
#include "Vector2.hpp"

#include <SFML/Graphics.hpp>

namespace game_engine {
namespace primitives {

class SFMLTexture : public ITexture, public sf::Texture {
    
public:
    SFMLTexture() : sf::Texture() {};
    SFMLTexture(const std::string& path) : sf::Texture(path), m_texturePath(path) {};

    bool loadFromFile(const std::string& path) override { return sf::Texture::loadFromFile(path); };

    // TODO: create image from pixels array
    Image copyToImage() const override {
        auto newImage = Image();
        const auto res = newImage.loadFromFile(m_texturePath);
        return newImage;
    };

    Vector2u getSize() const override { return sfVector2ToEngineVector2(sf::Texture::getSize()); };

private:
    std::string m_texturePath;
};

}
}
