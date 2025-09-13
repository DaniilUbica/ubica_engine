#pragma once

#include "Drawable.h"
#include "Primitives/Vector2.hpp"
#include "Primitives/Texture/Texture.hpp"

namespace game_engine {

/**
 * @class GameObject
 * @brief Base class for all game objects in the game engine.
 *
 * The GameObject class provides the fundamental properties and structure
 * common to all renderable objects in the game. It encapsulates position,
 * size, and visual representation through a sprite. This is an abstract
 * base class designed to be inherited by specific game object types.
 */
class GameObject : public Drawable {
protected:
    primitives::Vector2f m_size;
    primitives::Vector2f m_pos;

    GameObject(const primitives::Texture& texture);
    GameObject() = default;
    virtual ~GameObject() = default;

public:
    primitives::Vector2f getPosition() const;
    primitives::Vector2f getSize() const;
};

}
