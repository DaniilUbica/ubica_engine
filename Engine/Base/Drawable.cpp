#include "Drawable.h"

using namespace game_engine;

std::vector<Drawable*> Drawable::s_drawables = {};

Drawable::Drawable(const sf::Texture& texture) {
    m_texture = texture;
    m_sprite = std::make_shared<sf::Sprite>(m_texture);

    s_drawables.push_back(this);
}

Drawable::Drawable(sf::Drawable* drawable) {
    const auto sprite = dynamic_cast<sf::Sprite*>(drawable);
    m_have_sprite = sprite != nullptr;
    if (sprite) {
        s_drawables.push_back(this);
    }
}

Drawable::~Drawable() {
    const auto it = std::find(s_drawables.begin(), s_drawables.end(), this);
    if (it != s_drawables.end()) {
        s_drawables.erase(it);
    }
}

void Drawable::drawAllDrawableObjects(sf::RenderWindow& window) {
    for (const auto drawable : s_drawables) {
        window.draw(*drawable->getSprite());
    }
}
