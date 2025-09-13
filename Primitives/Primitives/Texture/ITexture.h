#pragma once

#include "Image/Image.hpp"

#include <string>

namespace game_engine {
namespace primitives {

class ITexture {
public:
    virtual ~ITexture() {};

    virtual bool loadFromFile(const std::string& path) = 0;
    virtual Image copyToImage() const = 0;
    virtual Vector2u getSize() const = 0;
};

}
}
