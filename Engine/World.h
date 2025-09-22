#pragma once

#include "Base/DrawableObject.h"
#include "Primitives/RenderWindow/RenderWindow.hpp"
#include "Primitives/Texture/Texture.hpp"
#include "Primitives/Sprite/Sprite.hpp"

namespace game_engine {

/**
 * @class World
 * @brief Singleton class that manages the game world's visual elements.
 *
 * The World class is responsible for loading, storing, and providing access to
 * the game world's background and border elements. It implements the singleton
 * pattern to ensure only one world instance exists throughout the game.
 */
class World : public DrawableObject {
private:
    static World*              m_world;

    primitives::Texture                 m_border_texture;
    primitives::Texture                 m_background_texture;
    std::shared_ptr<primitives::Sprite> m_background_sprite;
    std::vector<primitives::Sprite>     m_border_sprites;

    World() {};

    void draw(const primitives::RenderWindow& window) override;

public:
    World(World const& world) = delete;
    void operator=(World const&) = delete;
    ~World();

    static World* getWorld();

    /**
     * @brief Initializes the world with background and border textures.
     * @param background Texture to use for the world background
     * @param border Texture to use for the world borders
     *
     * This method must be called to set up the world before using any other functionality.
     * It loads the textures and creates the corresponding sprites.
     */
    void initWorld(const primitives::Texture& background, const primitives::Texture& border);

    std::vector<primitives::Sprite> getBorderSprites() const;
    std::shared_ptr<primitives::Sprite> getBackgroundSprite() const;
};

}
