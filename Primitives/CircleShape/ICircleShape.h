#pragma once

namespace game_engine {
namespace primitives {

class ICircleShape : public IDrawable {
public:
    virtual ~ICircleShape() {};

    virtual void move(const Vector2f& pos) = 0;

    virtual void setPosition(const Vector2f& pos) = 0;
    virtual void setRadius(float radius) = 0;
    virtual void setFillColor(const Color& color) = 0;

    virtual Color getFillColor() const = 0;
    virtual Vector2f getPosition() const = 0;
    virtual float getRadius() const = 0;
};

}
}
