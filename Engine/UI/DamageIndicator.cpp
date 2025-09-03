#include "DamageIndicator.h"

using namespace game_engine::ui;

static const uint TEXT_BORDER_SIZE = 1;
static const float TEXT_PATH_LENGTH = 100.0;

std::vector<indicator_t> DamageIndicatorsHolder::m_indicators = {};
DamageIndicatorsHolder* DamageIndicatorsHolder::m_instance = nullptr;

DamageIndicatorsHolder* DamageIndicatorsHolder::instance() {
    if (!m_instance) {
        m_instance = new DamageIndicatorsHolder();
    }

    return m_instance;
}

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

void DamageIndicatorsHolder::addIndicator(const sf::Vector2f& pos, int damage, float speed, damage_indicator::Direction direction, const sf::Font& font, uint size, const sf::Color& borderColor, const sf::Color& textColor) {
    m_indicators.push_back(std::make_unique<DamageIndicator>(pos, damage, speed, direction, font, size, borderColor, textColor));
}



sf::Vector2f DamageIndicator::getTextBordersPos() {
    const auto damageTextPos = m_damageText->getPosition();
    return { damageTextPos.x - TEXT_BORDER_SIZE / 2, damageTextPos.y - TEXT_BORDER_SIZE / 2 };
}

void DamageIndicator::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(*m_damageTextBorder.get());
    target.draw(*m_damageText.get());
}

DamageIndicator::DamageIndicator(const sf::Vector2f& pos, int damage, float speed, damage_indicator::Direction direction, const sf::Font& font, uint size, const sf::Color& borderColor, const sf::Color& textColor) : game_engine::Drawable(this) {
    m_damage = damage;
    m_textSpeed = speed;
    m_textDirection = direction;
    m_startPos = pos;
    m_currentPos = m_startPos;
    m_font = font;

    const std::string textString = "-" + std::to_string(m_damage);
    m_damageText = std::make_unique<sf::Text>(m_font, textString, size);
    m_damageTextBorder = std::make_unique<sf::Text>(m_font, textString, size + TEXT_BORDER_SIZE);

    m_damageText->setFillColor(textColor);
    m_damageTextBorder->setFillColor(borderColor);

    m_damageText->setPosition(m_currentPos);
    m_damageTextBorder->setPosition(getTextBordersPos());
}

void DamageIndicator::Update(float time) {
    if (m_textDirection == damage_indicator::Direction::FROM_BOTTOM_TO_TOP) {
        m_stopped = m_startPos.y - TEXT_PATH_LENGTH >= m_currentPos.y;
        if (!m_stopped) {
            m_currentPos.y -= m_textSpeed * time;
        }
    }

    m_damageText->setPosition(m_currentPos);
    m_damageTextBorder->setPosition(getTextBordersPos());
}
