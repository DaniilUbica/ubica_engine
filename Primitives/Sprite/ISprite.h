#pragma once

#include <stdint.h>

#include "IDrawable.h"
#include "Rect/Rect.hpp"
#include "Vector2.hpp"

namespace game_engine {
namespace primitives {

class ISprite : public IDrawable {
public:
    virtual ~ISprite() {};

    virtual void setPosition(const Vector2f& pos) = 0;
    virtual void setScale(const Vector2f& scale) = 0;
    virtual void setColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a) = 0;
    virtual void setRotation(int degrees) = 0;
    virtual void setOrigin(const Vector2f& origin) = 0;
    virtual void setTextureRect(const IntRect& rectangle) = 0;

    virtual FloatRect getGlobalBounds() const = 0;
    virtual IntRect getTextureRect() const = 0;
};

}
}
