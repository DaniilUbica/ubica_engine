#pragma once

#include "RenderWindow/IRenderWindow.h"
#include "Helpers.hpp"

#include <SFML/Graphics.hpp>

namespace game_engine {
namespace primitives {

class SFMLRenderWindow : public IRenderWindow, public sf::RenderWindow {
public:
    SFMLRenderWindow(const Vector2u& windowSize, const std::string& title)
        : sf::RenderWindow(sf::VideoMode(engineVector2ToSfVector2(windowSize)), title) {}

    void clear(const Color& color) override { sf::RenderWindow::clear(engineColorToSfColor(color)); };
    void close() override { sf::RenderWindow::close(); };
    void display() override { sf::RenderWindow::display(); };
    std::unique_ptr<Event> pollEvent() override { return sfEventToEngineEvent(sf::RenderWindow::pollEvent()); };

    void draw(std::shared_ptr<IDrawable> drawable) override {
        if (const auto sfDrawable = std::dynamic_pointer_cast<sf::Drawable>(drawable)) {
            sf::RenderWindow::draw(*sfDrawable);
        }
    }

    // TODO: don't create new View here
    void setView(const View& view) override {
        const auto sfView = sf::View(engineRectToSfRect(view.getViewRect()));
        sf::RenderWindow::setView(sfView);
    };

    bool isOpen() const override { return sf::RenderWindow::isOpen(); };
};

}
}
