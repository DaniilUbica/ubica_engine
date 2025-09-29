#pragma once

#include "DrawableObject.h"
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
class GameObject : public SpriteObject {
protected:
    GameObject(const primitives::Texture& texture);
    GameObject() = default;
    virtual ~GameObject() = default;

public:
    virtual void Update(float time);
};

}
