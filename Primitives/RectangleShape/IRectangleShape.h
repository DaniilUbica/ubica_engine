#pragma once

namespace game_engine {
namespace primitives {

class IRectangleShape : public IDrawable {
public:
    virtual ~IRectangleShape() {};

    virtual void move(const Vector2f& pos) = 0;

    virtual void setPosition(const Vector2f& pos) = 0;
    virtual void setSize(const Vector2f& size) = 0;
    virtual void setFillColor(const Color& color) = 0;

    virtual Color getFillColor() const = 0;
    virtual Vector2f getPosition() const = 0;
    virtual Vector2f getSize() const = 0;
};

}
}
