#pragma once

#include "Sprite/ISprite.h"
#include "Texture/Texture.hpp"
#include "Helpers.hpp"

#include <SFML/Graphics.hpp>

namespace game_engine {
namespace primitives {

class SFMLSprite : public ISprite, public sf::Sprite {
public:
    SFMLSprite(std::shared_ptr<ITexture> texture) : sf::Sprite(*std::dynamic_pointer_cast<sf::Texture>(texture))
    { };

    void setPosition(const Vector2f& pos) override {sf::Sprite::setPosition({ pos.x, pos.y }); };
    void setScale(const Vector2f& scale) override { sf::Sprite::setScale({ scale.x, scale.y }); };
    void setColor(const Color& color) override { sf::Sprite::setColor(engineColorToSfColor(color)); };
    void setRotation(int degrees) override { sf::Sprite::setRotation(sf::degrees(degrees)); };
    void setOrigin(const Vector2f& origin) override { sf::Sprite::setOrigin({ origin.x, origin.y }); };
    void setTextureRect(const IntRect& rectangle) override { sf::Sprite::setTextureRect(engineRectToSfRect(rectangle)); };

    FloatRect getGlobalBounds() const override { return sfRectToEngineRect(sf::Sprite::getGlobalBounds()); };
    IntRect getTextureRect() const override { return sfRectToEngineRect(sf::Sprite::getTextureRect()); };
};

}
}
