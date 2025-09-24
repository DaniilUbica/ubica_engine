#pragma once

#include "View/IView.h"
#include "Vector2.hpp"
#include "Rect.hpp"
#include "Helpers.hpp"

#include <SFML/Graphics.hpp>

namespace game_engine {
namespace primitives {

class SFMLView : public IView, public sf::View {

public:
    SFMLView(const FloatRect& viewRect) : sf::View(engineRectToSfRect(viewRect)) {};

    void setSize(const Vector2f& size) override { sf::View::setSize(engineVector2ToSfVector2(size)); };
    void setCenter(const Vector2f& center) override { sf::View::setCenter(engineVector2ToSfVector2(center)); };

    FloatRect getViewRect() const override { return sfRectToEngineRect(sf::FloatRect(sf::View::getCenter() - sf::View::getSize() / 2.f, sf::View::getSize())); };
};

}
}
