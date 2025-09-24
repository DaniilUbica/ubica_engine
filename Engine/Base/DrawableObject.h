#pragma once

#include "Primitives/Texture/Texture.hpp"
#include "Primitives/Sprite/Sprite.hpp"
#include "Primitives/RenderWindow/RenderWindow.hpp"

namespace game_engine {

/**
 * @class DrawableObject
 * @brief Base class for all drawable objects in the game engine.
 *
 * The DrawableObject class provides a foundation for all objects that can be rendered
 * to the screen. It manages textures, sprites, and provides a centralized
 * mechanism for drawing all drawable objects through a static method.
 *
 * @note This class uses the RAII (Resource Acquisition Is Initialization) pattern
 *       to manage SFML resources and automatically handles memory cleanup.
 */
class DrawableObject {
private:
    static std::vector<DrawableObject*> s_drawables;

    bool m_have_sprite = true;

protected:
    game_engine::primitives::Texture m_texture;
    std::shared_ptr<game_engine::primitives::Sprite> m_sprite;

public:

    /**
     * @brief Constructs a DrawableObject object with an optional texture.
     * @param texture The SFML texture to be used for this drawable object.
     *               Defaults to an empty texture if not provided.
     *
     * @note The object is automatically added to the static drawables list
     *       upon construction.
     */
    DrawableObject(const game_engine::primitives::Texture& texture = {});

    /**
     * @brief Constructs a DrawableObject object from an existing SFML drawable.
     * @param drawable Pointer to an SFML drawable object to be wrapped.
     *
     * @warning This constructor is intended for advanced use cases where
     *          existing SFML drawables need to be integrated into the
     *          game engine's drawing system.
     */
    DrawableObject(game_engine::primitives::Drawable* drawable);

    /**
     * @brief Virtual destructor for proper polymorphic destruction.
     *
     * Automatically removes the object from the static drawables list
     * and cleans up any allocated resources.
     */
    virtual ~DrawableObject();

    virtual void draw(const primitives::RenderWindow& window) = 0;

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
    static void drawAllDrawableObjects(game_engine::primitives::RenderWindow& window);

    std::shared_ptr<game_engine::primitives::Sprite> getSprite() const { return m_sprite; };
};

/**
 * @class SpriteObject
 * @brief Base class for drawable objects that use sprites.
 * Provides automatic drawing implementation for objects with sprites.
 */
class SpriteObject : public DrawableObject {
    using DrawableObject::DrawableObject;

public:
    /**
     * @brief Automatic drawing implementation for sprite-based objects.
     * Derived classes don't need to override this method.
     */
    void draw(const primitives::RenderWindow& window) override final {
        if (m_sprite) {
            window.draw(*m_sprite);
        }
    }
};

}
