#pragma once

#include <SFML/Graphics.hpp>

namespace game_engine {

class Drawable {
private:
    static std::vector<Drawable*> s_drawables;

    bool m_have_sprite = true;

protected:
    sf::Texture m_texture;
    std::shared_ptr<sf::Sprite> m_sprite;

public:
    Drawable(const sf::Texture& texture = {});
    Drawable(sf::Drawable* drawable);
    virtual ~Drawable();

    static void drawAllDrawableObjects(sf::RenderWindow& window);

    std::shared_ptr<sf::Sprite> getSprite() const { return m_sprite; };
};

}
