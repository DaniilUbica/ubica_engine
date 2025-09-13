#include "Drawable.h"

using namespace game_engine;

std::vector<Drawable*> Drawable::s_drawables = {};

Drawable::Drawable(const game_engine::primitives::Texture& texture) {
    m_texture = texture;
    m_sprite = std::make_shared<game_engine::primitives::Sprite>(m_texture);

    s_drawables.push_back(this);
}

Drawable::Drawable(game_engine::primitives::Drawable* drawable) {
    const auto sprite = dynamic_cast<game_engine::primitives::Sprite*>(drawable);
    m_have_sprite = !!dynamic_cast<game_engine::primitives::Sprite*>(drawable);
    s_drawables.push_back(this);
}

Drawable::~Drawable() {
    const auto it = std::find(s_drawables.begin(), s_drawables.end(), this);
    if (it != s_drawables.end()) {
        s_drawables.erase(it);
    }
}

void Drawable::drawAllDrawableObjects(game_engine::primitives::RenderWindow& window) {
    for (const auto drawable : s_drawables) {
        if (drawable->m_have_sprite) {
            window.draw(*drawable->getSprite());
        }
        else {
            if (const auto sf_drawable = dynamic_cast<game_engine::primitives::Drawable*>(drawable)) {
                window.draw(*sf_drawable);
            }
        }
    }
}
