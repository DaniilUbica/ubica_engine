#include "GameObject.h"

using namespace game_engine;

GameObject::GameObject(const primitives::Texture& texture) : SpriteObject(texture) {}

void GameObject::Update(float time) {
    m_sprite->setPosition(m_pos);
}
