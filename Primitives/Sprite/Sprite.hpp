#pragma once

#include "SpriteFactory.hpp"
#include "Sprite/ISprite.h"
#include "Texture/Texture.hpp"
#include "Drawable.h"

namespace game_engine {
namespace primitives {

class Sprite : public Drawable {
public:
    Sprite(const Texture& texture) { m_impl = createSprite(texture.m_impl); };

    void setPosition(const Vector2f& pos) { m_impl->setPosition(pos); };
    void setScale(const Vector2f& scale) { m_impl->setScale(scale); };
    void setColor(const Color& color) { m_impl->setColor(color); }
    void setRotation(int degrees) { m_impl->setRotation(degrees); };
    void setOrigin(const Vector2f& origin) { m_impl->setOrigin(origin); };
    void setTextureRect(const IntRect& rectangle) { m_impl->setTextureRect(rectangle); };

    FloatRect getGlobalBounds() const { return m_impl->getGlobalBounds(); };
    IntRect getTextureRect() const { return m_impl->getTextureRect(); };

private:
    std::shared_ptr<IDrawable> drawableImpl() const override { return m_impl; };

    std::shared_ptr<ISprite> m_impl;
};

}
}
