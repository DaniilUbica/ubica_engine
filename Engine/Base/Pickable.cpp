#include "Pickable.h"

using namespace game_engine;

Pickable::Pickable(std::shared_ptr<Character> character, const primitives::Texture& texture, primitives::Vector2f pos, bool attractable) : GameObject(texture) {
    m_character = character;
    m_pos = pos;
    m_attractable = attractable;
};

void Pickable::commonPicked() {
	m_picked = true;
}
