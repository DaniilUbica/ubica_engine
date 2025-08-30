#pragma once

#include <SFML/Graphics.hpp>

namespace game_engine {

/**
 * @class Drawable
 * @brief Base class for all drawable objects in the game engine.
 *
 * The Drawable class provides a foundation for all objects that can be rendered
 * to the screen. It manages textures, sprites, and provides a centralized
 * mechanism for drawing all drawable objects through a static method.
 *
 * @note This class uses the RAII (Resource Acquisition Is Initialization) pattern
 *       to manage SFML resources and automatically handles memory cleanup.
 */
class Drawable {
private:
    static std::vector<Drawable*> s_drawables;

    bool m_have_sprite = true;

protected:
    sf::Texture m_texture;
    std::shared_ptr<sf::Sprite> m_sprite;

public:

    /**
     * @brief Constructs a Drawable object with an optional texture.
     * @param texture The SFML texture to be used for this drawable object.
     *               Defaults to an empty texture if not provided.
     *
     * @note The object is automatically added to the static drawables list
     *       upon construction.
     */
    Drawable(const sf::Texture& texture = {});

    /**
     * @brief Constructs a Drawable object from an existing SFML drawable.
     * @param drawable Pointer to an SFML drawable object to be wrapped.
     *
     * @warning This constructor is intended for advanced use cases where
     *          existing SFML drawables need to be integrated into the
     *          game engine's drawing system.
     */
    Drawable(sf::Drawable* drawable);

    /**
     * @brief Virtual destructor for proper polymorphic destruction.
     *
     * Automatically removes the object from the static drawables list
     * and cleans up any allocated resources.
     */
    virtual ~Drawable();

    /**
     * @brief Static method to render all registered Drawable objects.
     * @param window The SFML render window where objects will be drawn.
     *
     * This method iterates through all existing Drawable instances and
     * renders them to the specified window. It should be called once
     * per frame in the main game loop.
     *
     * @code
     * // Example usage in game loop:
     * while (window.isOpen()) {
     *     // Update game logic...
     *     Drawable::drawAllDrawableObjects(window);
     * }
     * @endcode
     */
    static void drawAllDrawableObjects(sf::RenderWindow& window);

    std::shared_ptr<sf::Sprite> getSprite() const { return m_sprite; };
};

}
