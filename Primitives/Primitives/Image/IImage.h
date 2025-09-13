#pragma once

#include "Color.h"
#include "Vector2.hpp"

#include<string>

namespace game_engine {
namespace primitives {

class IImage {
public:
    virtual ~IImage() {};

    virtual bool loadFromFile(const std::string& path) = 0;
    virtual Color getPixelColor(const Vector2u& pixelPos) = 0;

};

}
}
