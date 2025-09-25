#pragma once

#include "DrawableObject.h"
#include "Animation/Animation.h"

namespace game_engine {

namespace ui {
    class HealthBar;
}

class Animation;

/**
 * @enum Direction
 * @brief Represents the  facing direction of a character.
 */
enum class Direction : bool {
    LEFT = 0,
    RIGHT = 1
};

/**
 * @class Character
 * @brief Base class for all character entities in the game.
 *
 * The Character class provides the fundamental properties and behaviors
 * common to all characters in the game. This is an abstract base class
 * that must be derived to create specific character types.
 */
class Character : public SpriteObject {
protected:
    float		                      m_health;
    float		                      m_speed;
    game_engine::primitives::Vector2f m_size;
    game_engine::primitives::Vector2f m_pos;
    std::unique_ptr<Animation>        m_run_animation;
    std::shared_ptr<ui::HealthBar>    m_health_bar;
    Direction                         m_direction = Direction::RIGHT;

private:
    void createDamageIndicator(int damage);

public:
    Character(const game_engine::primitives::Texture& texture);
    virtual ~Character() = default;

    /**
     * @brief Pure virtual update method to be implemented by derived classes.
     * @param time Elapsed time since last update
     */
    virtual void Update(float time) = 0;

    /**
     * @brief Applies damage to the character.
     * @param damage Amount of damage to apply
     */
    virtual void takeDamage(float damage, bool showIndicator = true);

    /**
     * @brief Restores health to the character.
     * @param health Amount of health to add
     */
    virtual void addHP(float health);

    /**
     * @brief Sets the character's position.
     * @param pos New position coordinates
     */
    void setPosition(const game_engine::primitives::Vector2f& pos);

    /**
     * @brief Sets the character's facing direction.
     * @param direction New direction
     */
    void setDirection(Direction direction);

    float getHP() const;
    game_engine::primitives::Vector2f getSize() const;
    game_engine::primitives::Vector2f getPosition() const;
    Direction getDirection() const;
    std::shared_ptr<ui::HealthBar> getHealthBar() const;
};

}
