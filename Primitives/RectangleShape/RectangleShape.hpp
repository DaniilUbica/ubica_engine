#pragma once

#include "RectangleShapeFactory.hpp"

namespace game_engine {
namespace primitives {

class RectangleShape : public Drawable {
public:
    RectangleShape() : m_impl(createRectangleShape()) {};

    void move(const Vector2f& pos) {};

    void setPosition(const Vector2f& pos) { m_impl->setPosition(pos); };
    void setSize(const Vector2f& size) { m_impl->setSize(size); };
    void setFillColor(const Color& color) { m_impl->setFillColor(color); };

    Color getFillColor() const {};
    Vector2f getPosition() const {};
    Vector2f getSize() const {};

private:
    std::shared_ptr<IDrawable> drawableImpl() const override { return m_impl; };

    std::shared_ptr<IRectangleShape> m_impl;
};

}
}
