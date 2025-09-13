#pragma once

#include "RenderWindow/IRenderWindow.h"

#include <SFML/Graphics.hpp>

namespace game_engine {
namespace primitives {

class SFMLRenderWindow : public IRenderWindow, public sf::RenderWindow {
public:
    SFMLRenderWindow(const Vector2u& windowSize, const std::string& title)
        : sf::RenderWindow(sf::VideoMode(engineVector2ToSfVector2(windowSize)), title) {}

    void clear(uint8_t r, uint8_t g, uint8_t b, uint8_t a) override { sf::RenderWindow::clear({ r, g, b, a }); };
    void close() override { sf::RenderWindow::close(); };
    void display() override { sf::RenderWindow::display(); };
    std::unique_ptr<Event> pollEvent() override { return sfEventToEngineEvent(sf::RenderWindow::pollEvent()); };

    void draw(std::shared_ptr<IDrawable> drawable) override {
        if (const auto sfDrawable = std::dynamic_pointer_cast<sf::Drawable>(drawable)) {
            sf::RenderWindow::draw(*sfDrawable);
        }
    }

    bool isOpen() const override { return sf::RenderWindow::isOpen(); };
};

}
}
