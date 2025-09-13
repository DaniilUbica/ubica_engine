#include "GameObject.h"

using namespace game_engine;

GameObject::GameObject(const primitives::Texture& texture) {}

primitives::Vector2f GameObject::getPosition() const {
    return m_pos;
}

primitives::Vector2f GameObject::getSize() const {
    return m_size;
}
