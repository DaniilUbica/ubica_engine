#include "DrawableObject.h"

#include "Constants.h"

using namespace game_engine;

std::vector<DrawableObject*> DrawableObject::s_drawables = {};
bool DrawableObject::s_needSort = false;

DrawableObject::DrawableObject() {
    s_drawables.push_back(this);
    s_needSort = true;
}

DrawableObject::DrawableObject(int z) : m_z(z) {
    s_drawables.push_back(this);
    s_needSort = true;
}

DrawableObject::~DrawableObject() {
    const auto it = std::find(s_drawables.begin(), s_drawables.end(), this);
    if (it != s_drawables.end()) {
        s_drawables.erase(it);
        s_needSort = true;
    }
}

void DrawableObject::drawAllDrawableObjects(game_engine::primitives::RenderWindow& window) {
    if (s_needSort) {
        std::sort(s_drawables.begin(), s_drawables.end(), [](DrawableObject* a, DrawableObject* b) {
            return a->z() < b->z();
        });
        s_needSort = false;
    }

    for (const auto drawable : s_drawables) {
        drawable->draw(window);
    }
}

void DrawableObject::setZ(int z) {
    if (m_z != z) {
        m_z = z;
        s_needSort = true;
    }
}

SpriteObject::SpriteObject(const game_engine::primitives::Texture& texture) : DrawableObject(SPRITE_OBJECT_Z) {
    m_texture = texture;
    m_sprite = std::make_shared<game_engine::primitives::Sprite>(m_texture);
}
