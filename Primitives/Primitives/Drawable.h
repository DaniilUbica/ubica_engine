#pragma once

#include "IDrawable.h"

#include <memory>

namespace game_engine {
namespace primitives {

class RenderWindow;

class Drawable {
public:
    virtual ~Drawable() {};

    virtual void draw(const RenderWindow& window) = 0;
    virtual std::shared_ptr<IDrawable> drawableImpl() const = 0;
};

}
}
