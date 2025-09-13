#pragma once

#include "CircleShape/ICircleShape.h"

#include <SFML/Graphics.hpp>

namespace game_engine {
namespace primitives {

class SFMLCircleShape : public ICircleShape, public sf::CircleShape {

public:
    SFMLCircleShape() : sf::CircleShape() {};

    virtual void move(const Vector2f& pos) override { sf::CircleShape::move(engineVector2ToSfVector2(pos)); };

    void setPosition(const Vector2f& pos) override { sf::CircleShape::setPosition(engineVector2ToSfVector2(pos)); };
    void setRadius(float radius) override { sf::CircleShape::setRadius(radius); };
    void setFillColor(const Color& color) override { sf::CircleShape::setFillColor(engineColorToSfColor(color)); };

    virtual Color getFillColor() const override { return sfColorToEngineColor(sf::CircleShape::getFillColor()); };
    virtual Vector2f getPosition() const override { return sfVector2ToEngineVector2(sf::CircleShape::getPosition()); };
    virtual float getRadius() const override { return sf::CircleShape::getRadius(); };
};

}
}
