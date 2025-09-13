#pragma once

#include "ImageFactory.hpp"

namespace game_engine {
namespace primitives {

class Image {
public:
    Image() : m_impl(createImage()) {};
    Image(const std::string& path) { m_impl = createImage(); m_impl->loadFromFile(path); };

    [[nodiscard]] bool loadFromFile(const std::string& path) { return m_impl->loadFromFile(path); };
    [[nodiscard]] Color getPixelColor(const Vector2u& pixelPos) { return m_impl->getPixelColor(pixelPos); };

private:
    std::shared_ptr<IImage> m_impl;
};

}
}
