#pragma once

#include "RenderWindowFactory.hpp"
#include "Event.hpp"
#include "Vector2.hpp"
#include "Drawable.h"
#include "Color.h"

namespace game_engine {
namespace primitives {

class RenderWindow {
public:
    RenderWindow(const Vector2u& windowSize, const std::string& title) : m_impl(createRenderWindow(windowSize, title)) {};

    void clear(const Color& color) { m_impl->clear(color); };
    void close() { m_impl->close(); };
    void display() { m_impl->display(); };
    [[nodiscard]] std::unique_ptr<Event> pollEvent() const { return m_impl->pollEvent(); };
    void draw(const Drawable& drawable) const { m_impl->draw(drawable.drawableImpl()); };
    void setView(const View& view) {  };

    bool isOpen() const { return m_impl->isOpen(); };

private:
    std::unique_ptr<IRenderWindow> m_impl;
};

}
}
