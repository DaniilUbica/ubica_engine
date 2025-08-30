#include "GameObject.h"

using namespace game_engine;

GameObject::GameObject(const sf::Texture& texture) : Drawable(texture) {}

sf::Vector2f GameObject::getPosition() const {
    return m_pos;
}

sf::Vector2f GameObject::getSize() const {
    return m_size;
}
