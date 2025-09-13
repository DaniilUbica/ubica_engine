#pragma once

#include "Primitives/RectangleShape/RectangleShape.hpp"
#include "Primitives/Vector2.hpp"

namespace game_engine {
namespace ui {

/**
 * @class HealthBar
 * @brief A UI element that visually represents health points with a customizable bar.
 *
 * The HealthBar class displays a health indicator consisting of three rectangular elements:
 * a border, background, and filled health portion. It can be used as either a static UI element
 * or dynamically positioned relative to a parent object (like a character).
 */
class HealthBar {
private:
    primitives::RectangleShape m_border;
    primitives::RectangleShape m_background;
    primitives::RectangleShape m_health_bar;
    primitives::Vector2f       m_pos;
    primitives::Vector2f       m_size;
    primitives::Vector2f       m_parent_size;
    float              m_health;
    float              m_chunk_size;
    float              m_border_size = 2.0;
    float              m_parent_offset = 7.0;
    bool               m_is_static;

public:

    /**
     * @brief Constructs a HealthBar with specified visual properties.
     * @param size The size dimensions of the health bar
     * @param pos The initial position coordinates
     * @param health The initial health value
     * @param border_color Color of the health bar border
     * @param background_color Color of the health bar background
     * @param health_color Color of the health fill portion
     * @param is_static Whether this is a static UI element (true) or follows a parent (false)
     * @param parent_size Size of the parent object for dynamic positioning (required if is_static = false)
     */
    HealthBar(primitives::Vector2f size, primitives::Vector2f pos, float health, primitives::Color border_color,
              primitives::Color background_color, primitives::Color health_color, bool is_static = true, primitives::Vector2f parent_size = { -1, -1 });

    /**
     * @brief Updates the health bar's state and position.
     * @param health The new health value to display
     * @param pos The new position coordinates (for dynamic health bars)
     *
     * For static health bars, only the health value is updated. For dynamic health bars,
     * both the health value and position are updated relative to the parent object.
     */
    void Update(float health, primitives::Vector2f pos);
};

}
}
