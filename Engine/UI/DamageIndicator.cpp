#include "DamageIndicator.h"

using namespace game_engine;
using namespace game_engine::ui;

static const uint TEXT_BORDER_SIZE = 1;
static const float TEXT_PATH_LENGTH = 100.0;

std::vector<indicator_t> DamageIndicatorsHolder::m_indicators = {};

void DamageIndicatorsHolder::Update(float time) {
    for (const auto& indicator : m_indicators) {
        indicator->Update(time);
    }

    m_indicators.erase(std::remove_if(m_indicators.begin(), m_indicators.end(),
            [](const std::unique_ptr<DamageIndicator>& indicator) {
                return indicator->stopped();
            }), m_indicators.end()
    );
}

void DamageIndicatorsHolder::addIndicator(const primitives::Vector2f& pos, int damage, float speed, damage_indicator::Direction direction, const primitives::Font& font, uint size, const primitives::Color& borderColor, const primitives::Color& textColor, std::weak_ptr<DrawableObject> parent) {
    m_indicators.push_back(std::make_unique<DamageIndicator>(pos, damage, speed, direction, font, size, borderColor, textColor, parent));
}



primitives::Vector2f DamageIndicator::getTextBordersPos() {
    const auto damageTextPos = m_damageText->getPosition();
    return { damageTextPos.x - TEXT_BORDER_SIZE / 2, damageTextPos.y - TEXT_BORDER_SIZE / 2 };
}

void DamageIndicator::draw(const primitives::RenderWindow& window) {
    window.draw(*m_damageTextBorder);
    window.draw(*m_damageText);
}

DamageIndicator::DamageIndicator(const primitives::Vector2f& pos, int damage, float speed, damage_indicator::Direction direction, const primitives::Font& font, uint size, const primitives::Color& borderColor, const primitives::Color& textColor, std::weak_ptr<DrawableObject> parent) {
    m_damage = damage;
    m_textSpeed = speed;
    m_textDirection = direction;
    m_startPos = pos;
    m_currentPos = m_startPos;
    m_font = font;
    m_parent = parent;

    if (const auto sp = m_parent.lock()) {
        setZ(sp->z() - 1);
    }

    const std::string textString = "-" + std::to_string(m_damage);
    m_damageText = std::make_unique<primitives::Text>(m_font, textString, size);
    m_damageTextBorder = std::make_unique<primitives::Text>(m_font, textString, size + TEXT_BORDER_SIZE);

    m_damageText->setFillColor(textColor);
    m_damageTextBorder->setFillColor(borderColor);

    m_damageText->setPosition(m_currentPos);
    m_damageTextBorder->setPosition(getTextBordersPos());
}

void DamageIndicator::Update(float time) {
    if (m_textDirection == damage_indicator::Direction::FROM_BOTTOM_TO_TOP) {
        m_stopped = m_startPos.y - TEXT_PATH_LENGTH >= m_currentPos.y || m_parent.expired();
        if (!m_stopped) {
            m_currentPos.y -= m_textSpeed * time;
        }
    }

    m_damageText->setPosition(m_currentPos);
    m_damageTextBorder->setPosition(getTextBordersPos());
}
