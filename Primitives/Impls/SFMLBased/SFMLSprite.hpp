#pragma once

#include "Sprite/ISprite.h"
#include "Texture/Texture.hpp"

#include <SFML/Graphics.hpp>

namespace game_engine {
namespace primitives {

namespace {
Rect<float> sfRectToEngineRect(const sf::FloatRect& sfRect) {
    return { sfRect.position.x, sfRect.position.y, sfRect.size.x, sfRect.size.y };
}
}

class SFMLSprite : public ISprite {
public:
    SFMLSprite(std::shared_ptr<ITexture> texture) { m_sfSprite = std::make_unique<sf::Sprite>(std::static_pointer_cast<SFMLTexture>(texture)->m_sfTexture); };
    
    void setPosition(const Vector2f& pos) override { m_sfSprite->setPosition({ pos.x, pos.y }); };
    void setScale(const Vector2f& scale) override { m_sfSprite->setScale({ scale.x, scale.y }); };
    void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) override { m_sfSprite->setColor({ r, g, b, a }); };
    void setRotation(int degrees) override { m_sfSprite->setRotation(sf::degrees(degrees)); };
    void setOrigin(const Vector2f& origin) override { m_sfSprite->setOrigin({ origin.x, origin.y }); };
    
    Rect<float> getGlobalBounds() const override { return sfRectToEngineRect(m_sfSprite->getGlobalBounds()); };
    
private:
    std::unique_ptr<sf::Sprite> m_sfSprite;
};

}
}
