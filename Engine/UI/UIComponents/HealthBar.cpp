#include "HealthBar.h"

#include "Constants.h"

using namespace game_engine;
using namespace ui;

void HealthBar::draw(const primitives::RenderWindow& window) {
    window.draw(m_border);
    window.draw(m_background);
    window.draw(m_health_bar);
}

HealthBar::HealthBar(primitives::Vector2f size, primitives::Vector2f pos, float health, primitives::Color border_color,
    primitives::Color background_color, primitives::Color health_color, bool is_static, primitives::Vector2f parent_size) {

    m_size = size;
    m_pos = primitives::Vector2f(pos.x + m_parent_size.x / 2 - m_size.x / 2, pos.y - m_size.y - m_parent_offset);
    m_parent_size = parent_size;
    m_health = health;
    m_is_static = is_static;

    primitives::Vector2f border_size = m_size;
    m_size -= primitives::Vector2f(m_border_size * 2, m_border_size * 2);
    primitives::Vector2f border_pos = m_pos;
    m_pos += primitives::Vector2f(m_border_size * 2, m_border_size * 2);

    m_border.setPosition(border_pos);
    m_background.setPosition(m_pos);
    m_health_bar.setPosition(m_pos);

    m_border.setSize(border_size);
    m_border.setFillColor(border_color);

    m_background.setSize(m_size);
    m_background.setFillColor(background_color);

    m_health_bar.setFillColor(health_color);
    m_health_bar.setSize(m_size);

    m_chunk_size = m_size.x / health;
}

void HealthBar::Update(float health, primitives::Vector2f pos) {
    if (!m_is_static) {
        m_pos = primitives::Vector2f(pos.x + m_parent_size.x / 2 - m_size.x / 2 - m_border_size, pos.y - m_size.y - m_parent_offset);

        primitives::Vector2f border_pos = m_pos;
        m_pos += primitives::Vector2f(m_border_size, m_border_size);

        m_border.setPosition(border_pos);
        m_background.setPosition(m_pos);
        m_health_bar.setPosition(m_pos);
    }

    static float prevHealthValue = m_health;
    static bool isAnimating = false;

    primitives::Vector2f new_size = m_health_bar.getSize();
    const auto target_width = m_chunk_size * health;

    if (prevHealthValue != health) {
        isAnimating = true;
    }

    if (isAnimating) {
        const auto animationDirection = (target_width > new_size.x) ? 1 : -1;
        new_size.x += animationDirection * HEALTH_BAR_ANIMATION_SPEED;

        if ((animationDirection > 0 && new_size.x >= target_width) || (animationDirection < 0 && new_size.x <= target_width)) {
            new_size.x = target_width;
            isAnimating = false;
            prevHealthValue = health;
        }
    }
    else {
        new_size = primitives::Vector2f(target_width, m_size.y);
    }

    if (new_size.x < 0) {
        new_size.x = 0;
    }

    m_health = health;
    m_health_bar.setSize(new_size);
}
