#pragma once

#include "Drawable.h"
#include "CircleShapeFactory.hpp"
#include "RenderWindow/RenderWindow.hpp"

namespace game_engine {
namespace primitives {

class CircleShape : public Drawable {
public:
    CircleShape() : m_impl(createCircleShape()) {};

    void move(const Vector2f& pos) { m_impl->move(pos); };

    void setPosition(const Vector2f& pos) { m_impl->setPosition(pos); };
    void setRadius(float radius) { m_impl->setRadius(radius); };
    void setFillColor(const Color& color) { m_impl->setFillColor(color); };

    Color getFillColor() const { return m_impl->getFillColor(); };
    float getRadius() const { return m_impl->getRadius(); };
    Vector2f getPosition() const { return m_impl->getPosition(); };

    void draw(const RenderWindow& window) override { window.draw(*this); };

private:
    std::shared_ptr<IDrawable> drawableImpl() const override { return m_impl; };

    std::shared_ptr<ICircleShape> m_impl;
};

}
}
