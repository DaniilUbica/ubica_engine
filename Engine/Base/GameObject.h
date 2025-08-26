#pragma once

#include <SFML/Graphics.hpp>

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
class GameObject {
protected:
    sf::Vector2f                m_size;
    sf::Vector2f                m_pos;
    sf::Texture                 m_texture;
    std::shared_ptr<sf::Sprite> m_sprite;

    GameObject() = default;
    virtual ~GameObject() = default;

public:
    std::shared_ptr<sf::Sprite> getSprite() const;
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;
};

}
