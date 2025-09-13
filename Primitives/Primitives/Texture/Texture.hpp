#pragma once

#include "Vector2.hpp"
#include "Image/Image.hpp"
#include "TextureFactory.hpp"

namespace game_engine {
namespace primitives {

class Texture {
    friend class Sprite;
public:
    Texture() : m_impl(createTexture()) {};
    Texture(const std::string& path) { m_impl = createTexture(); m_impl->loadFromFile(path); };

    [[nodiscard]] bool loadFromFile(const std::string& path) { return m_impl->loadFromFile(path); };
    [[nodiscard]] Image copyToImage() const { return m_impl->copyToImage(); };
    [[nodiscard]] Vector2u getSize() const { return m_impl->getSize(); }

private:
    std::shared_ptr<ITexture> m_impl;
};

}
}
