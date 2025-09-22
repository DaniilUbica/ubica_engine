#pragma once

#include "Drawable.h"
#include "RectangleShapeFactory.hpp"
#include "RenderWindow/RenderWindow.hpp"

namespace game_engine {
namespace primitives {

class RectangleShape : public Drawable {
public:
    RectangleShape() : m_impl(createRectangleShape()) {};

    void move(const Vector2f& pos) {};

    void setPosition(const Vector2f& pos) { m_impl->setPosition(pos); };
    void setSize(const Vector2f& size) { m_impl->setSize(size); };
    void setFillColor(const Color& color) { m_impl->setFillColor(color); };

    Color getFillColor() const { return m_impl->getFillColor(); };
    Vector2f getPosition() const { return m_impl->getPosition(); };
    Vector2f getSize() const { return m_impl->getSize(); };

    void draw(const RenderWindow& window) override { window.draw(*this); };

private:
    std::shared_ptr<IDrawable> drawableImpl() const override { return m_impl; };

    std::shared_ptr<IRectangleShape> m_impl;
};

}
}
