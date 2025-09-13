#pragma once

#include "CircleShapeFactory.hpp"

namespace game_engine {
namespace primitives {

class CircleShape : public Drawable {
public:
    CircleShape() : m_impl(createCircleShape()) {};

    void move(const Vector2f& pos) {};

    void setPosition(const Vector2f& pos) { m_impl->setPosition(pos); };
    void setRadius(float radius) { m_impl->setRadius(radius); };
    void setFillColor(const Color& color) { m_impl->setFillColor(color); };

    Color getFillColor() const {};
    float getRadius() const {};
    Vector2f getSize() const {};

private:
    std::shared_ptr<IDrawable> drawableImpl() const override { return m_impl; };

    std::shared_ptr<ICircleShape> m_impl;
};

}
}
