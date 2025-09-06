#pragma once

#include "SpriteFactory.hpp"
#include "Sprite/ISprite.h"

namespace game_engine {
namespace primitives {

class Sprite {
public:
    Sprite() { m_impl = createSprite(); };

    void setPosition(const Vector2f& pos) { m_impl->setPosition(pos); };
    void setScale(const Vector2f& scale) { m_impl->setScale(scale); };
    void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) { m_impl->setColor(r, g, b, a); }
    void setRotation(int degrees) { m_impl->setRotation(degrees); };
    void setOrigin(const Vector2f& origin) { m_impl->setOrigin(origin); };

    Rect<float> getGlobalBounds() const { return m_impl->getGlobalBounds(); };

private:
    std::unique_ptr<ISprite> m_impl;
};

}
}
