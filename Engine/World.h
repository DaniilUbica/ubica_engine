#pragma once

#include "Base/Drawable.h"

namespace game_engine {

/**
 * @class World
 * @brief Singleton class that manages the game world's visual elements.
 *
 * The World class is responsible for loading, storing, and providing access to
 * the game world's background and border elements. It implements the singleton
 * pattern to ensure only one world instance exists throughout the game.
 */
class World : public game_engine::Drawable, public sf::Drawable {
private:
    static World*              m_world;

    sf::Texture                 m_border_texture;
    sf::Texture                 m_background_texture;
    std::shared_ptr<sf::Sprite> m_background_sprite;
    std::vector<sf::Sprite>     m_border_sprites;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    World() : game_engine::Drawable(this) {};
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
    void initWorld(const sf::Texture& background, const sf::Texture& border);

    std::vector<sf::Sprite> getBorderSprites() const;
    std::shared_ptr<sf::Sprite> getBackgroundSprite() const;
};

}
