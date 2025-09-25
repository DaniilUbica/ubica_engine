#pragma once

#include "Text/IText.h"
#include "Helpers.hpp"

#include <SFML/Graphics.hpp>

namespace game_engine {
namespace primitives {

class SFMLText : public IText, public sf::Text {

public:
    SFMLText(std::shared_ptr<IFont> font) : sf::Text(*std::dynamic_pointer_cast<sf::Font>(font)) {};

    void setText(const std::string& text) { sf::Text::setString(text); };
    void setPosition(const Vector2f& pos) { sf::Text::setPosition(engineVector2ToSfVector2(pos)); };
    void setSize(uint size) { sf::Text::setCharacterSize(size); };
    void setFillColor(const Color& color) { sf::Text::setFillColor(engineColorToSfColor(color)); };

    Vector2f getPosition() const { return sfVector2ToEngineVector2(sf::Text::getPosition()); };
};

}
}
