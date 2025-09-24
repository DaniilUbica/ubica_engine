#pragma once

#include "IDrawable.h"
#include "Event.hpp"
#include "View/View.hpp"

#include <memory>

namespace game_engine {
namespace primitives {

class IRenderWindow {
public:
    virtual ~IRenderWindow() {};

    virtual void clear(const Color& color) = 0;
    virtual void close() = 0;
    virtual void display() = 0;
    virtual std::unique_ptr<Event> pollEvent() = 0;
    virtual void draw(std::shared_ptr<IDrawable> drawable) = 0;
    virtual void setView(const View& view) = 0;

    virtual bool isOpen() const = 0;


};

}
}
