#pragma once

#include "RenderWindowFactory.hpp"
#include "Event.hpp"
#include "Vector2.hpp"

namespace game_engine {
namespace primitives {

class RenderWindow {
public:
    RenderWindow(const Vector2u& windowSize, const std::string& title) : m_impl(createRenderWindow(windowSize, title)) {};

    void clear(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) { m_impl->clear(r, g, b, a); };
    void close() { m_impl->close(); };
    void display() { m_impl->display(); };
    [[nodiscard]] std::unique_ptr<Event> pollEvent() const { return m_impl->pollEvent(); };
    void draw(const Drawable& drawable) const { m_impl->draw(drawable.drawableImpl()); };

    bool isOpen() const { return m_impl->isOpen(); };

private:
    std::unique_ptr<IRenderWindow> m_impl;
};

}
}
