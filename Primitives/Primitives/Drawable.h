#pragma once

#include "IDrawable.h"

#include <memory>

namespace game_engine {
namespace primitives {

class Drawable {
public:
    virtual ~Drawable() {};

    virtual std::shared_ptr<IDrawable> drawableImpl() const = 0;
};

}
}
