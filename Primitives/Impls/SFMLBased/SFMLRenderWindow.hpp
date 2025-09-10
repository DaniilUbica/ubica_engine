#pragma once

#include "RenderWindow/IRenderWindow.h"

#include <SFML/Graphics.hpp>

namespace game_engine {
namespace primitives {

class SFMLRenderWindow : public IRenderWindow {
public:
    SFMLRenderWindow(const Vector2u& windowSize, const std::string& title) : m_sfRenderWindow(sf::RenderWindow(sf::VideoMode(engineVector2ToSfVector2(windowSize)), title)) {}

    void clear(uint8_t r, uint8_t g, uint8_t b, uint8_t a) override { m_sfRenderWindow.clear({ r, g, b, a }); };
    void close() override { m_sfRenderWindow.close(); };
    void display() override { m_sfRenderWindow.pollEvent(); m_sfRenderWindow.display(); };
    void draw(std::shared_ptr<IDrawable> drawable) override {
        if (const auto sfDrawable = std::dynamic_pointer_cast<sf::Drawable>(drawable)) {
            m_sfRenderWindow.draw(*sfDrawable);
        }
    };

    bool isOpen() const override { return m_sfRenderWindow.isOpen(); };

private:
    sf::RenderWindow m_sfRenderWindow;
};

}
}
