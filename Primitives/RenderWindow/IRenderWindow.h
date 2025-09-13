#pragma once

#include "IDrawable.h"

namespace game_engine {
namespace primitives {

class IRenderWindow {
public:
    virtual ~IRenderWindow() {};

    virtual void clear(uint8_t r, uint8_t g, uint8_t b, uint8_t a) = 0;
    virtual void close() = 0;
    virtual void display() = 0;
    virtual void draw(std::shared_ptr<IDrawable> drawable) = 0;

    virtual bool isOpen() const = 0;


};

}
}
