#include "Character.h"

#include "Constants.h"
#include "UI/UIComponents/DamageIndicator.h"

using namespace game_engine;
using namespace ui;

void Character::createDamageIndicator(int damage) {
    const auto pos = m_pos + m_size / 2.f - static_cast<float>(FONT_SIZE / 2);
//    DamageIndicatorsHolder::addIndicator(pos, damage, DAMAGE_INDICATOR_SPEED, damage_indicator::Direction::FROM_BOTTOM_TO_TOP, FONT, FONT_SIZE, primitives::colors::Black, primitives::colors::White, std::dynamic_pointer_cast<DrawableObject>(shared_from_this()));
}

Character::Character(const game_engine::primitives::Texture& texture) : SpriteObject(texture) {}

void Character::takeDamage(float damage, bool showIndicator) {
    m_health -= damage;
    if (showIndicator && m_health > 0) {
        createDamageIndicator(damage);
    }
}

void Character::addHP(float health) {
    m_health += health;
}

void Character::setDirection(Direction direction) {
    m_direction = direction;
}

float Character::getHP() const {
    return m_health;
}

Direction Character::getDirection() const {
    return m_direction;
}

std::shared_ptr<HealthBar> Character::getHealthBar() const {
    return m_health_bar;
}
