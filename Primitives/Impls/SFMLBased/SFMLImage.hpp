#pragma once

#include "Image/IImage.h"
#include "Helpers.hpp"

#include <SFML/Graphics.hpp>

namespace game_engine {
namespace primitives {

class SFMLImage : public IImage, public sf::Image {

public:
    SFMLImage() : sf::Image() {};
    SFMLImage(const std::string& path) : sf::Image(path) {};

    bool loadFromFile(const std::string& path) override { return sf::Image::loadFromFile(path); };
    Color getPixelColor(const Vector2u& pixelPos) override { return sfColorToEngineColor(sf::Image::getPixel(engineVector2ToSfVector2(pixelPos))); };
};

}
}
