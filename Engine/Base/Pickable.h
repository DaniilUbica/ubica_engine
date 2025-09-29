#pragma once

#include "GameObject.h"
#include "Character.h"

namespace game_engine {

/**
 * @class Pickable
 * @brief Abstract base class for objects that can be picked up or collected in the game.
 *
 * The Pickable class extends GameObject and adds functionality for items that can be
 * collected by player or other entities. It provides a common interface for handling
 * pickup events and tracking the collected state.
 */
class Pickable : public GameObject {
protected:
    bool m_picked = false;
    bool m_attractable = false;
    std::shared_ptr<Character> m_character;

    Pickable(std::shared_ptr<Character> character, const primitives::Texture& texture, primitives::Vector2f pos, bool attractable = false);

    /**
     * @brief Common handling logic for when an object is picked up.
     *
     * This protected method provides shared functionality that should be executed
     * whenever any pickable object is collected. Derived classes can call this
     * method as part of their onPicked() implementation.
     */
    void commonPicked();

public:

    /**
     * @brief Pure virtual method called when the object is picked up.
     *
     * Derived classes must implement this method to define specific behavior
     * that occurs when the object is collected (e.g., granting points, power-ups,
     * or triggering events).
     */
    virtual void onPicked() = 0;

    bool picked() const { return m_picked; };
    bool attractable() const { return m_attractable; };
};

}
