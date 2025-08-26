#include "Pickable.h"

using namespace game_engine;

void Pickable::commonPicked() {
	m_picked = true;
}

bool Pickable::getPicked() const {
	return m_picked;
}
