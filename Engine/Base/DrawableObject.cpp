#include "DrawableObject.h"

using namespace game_engine;

std::vector<DrawableObject*> DrawableObject::s_drawables = {};

DrawableObject::DrawableObject(const game_engine::primitives::Texture& texture) {
    m_texture = texture;
    m_sprite = std::make_shared<game_engine::primitives::Sprite>(m_texture);

    s_drawables.push_back(this);
}

DrawableObject::DrawableObject(game_engine::primitives::Drawable* drawable) {
    const auto sprite = dynamic_cast<game_engine::primitives::Sprite*>(drawable);
    m_have_sprite = !!dynamic_cast<game_engine::primitives::Sprite*>(drawable);
    s_drawables.push_back(this);
}

DrawableObject::~DrawableObject() {
    const auto it = std::find(s_drawables.begin(), s_drawables.end(), this);
    if (it != s_drawables.end()) {
        s_drawables.erase(it);
    }
}

void DrawableObject::drawAllDrawableObjects(game_engine::primitives::RenderWindow& window) {
    for (const auto drawable : s_drawables) {
        drawable->draw(window);
    }
}
