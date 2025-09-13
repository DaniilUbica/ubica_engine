#pragma once

#include "RectangleShape/IRectangleShape.h"

#include <SFML/Graphics.hpp>

namespace game_engine {
namespace primitives {

class SFMLRectangleShape : public IRectangleShape, public sf::RectangleShape {

public:
    SFMLRectangleShape() : sf::RectangleShape() {};

    virtual void move(const Vector2f& pos) override { sf::RectangleShape::move(engineVector2ToSfVector2(pos)); };

    void setPosition(const Vector2f& pos) override { sf::RectangleShape::setPosition(engineVector2ToSfVector2(pos)); };
    void setSize(const Vector2f& size) override { sf::RectangleShape::setSize(engineVector2ToSfVector2(size)); };
    void setFillColor(const Color& color) override { sf::RectangleShape::setFillColor(engineColorToSfColor(color)); };

    virtual Color getFillColor() const override { return sfColorToEngineColor(sf::RectangleShape::getFillColor()); };
    virtual Vector2f getPosition() const override { return sfVector2ToEngineVector2(sf::RectangleShape::getPosition()); };
    virtual Vector2f getSize() const override { return sfVector2ToEngineVector2(sf::RectangleShape::getSize()); };
};

}
}
