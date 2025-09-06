#pragma once

#include "TextureFactory.hpp"

namespace game_engine {
namespace primitives {

class Texture {
    friend class Sprite;
public:
    Texture() { m_impl = createTexture(); };
    Texture(const std::string& path) { m_impl = createTexture(); m_impl->loadFromFile(path); };

    [[nodiscard]]  bool loadFromFile(const std::string& path) { return m_impl->loadFromFile(path); };

private:
    std::shared_ptr<ITexture> m_impl;
};

}
}
