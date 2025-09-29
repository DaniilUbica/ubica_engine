#pragma once

#include "IDrawable.h"

namespace game_engine {
namespace primitives {

class IText : public IDrawable {
public:
    virtual ~IText() {};

    virtual void setText(const std::string& text) = 0;
    virtual void setPosition(const Vector2f& pos) = 0;
    virtual void setSize(unsigned int size) = 0;
    virtual void setFillColor(const Color& color) = 0;

    virtual Vector2f getPosition() const = 0;
};

}
}
