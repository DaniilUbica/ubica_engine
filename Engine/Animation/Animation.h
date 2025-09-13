#pragma once

#include "Primitives/Rect.hpp"
#include "Primitives/Sprite/Sprite.hpp"

#include <vector>
#include <map>

namespace game_engine {

/**
 * @class Animation
 * @brief Handles sprite animation using a series of texture rectangles.
 *
 * The Animation class manages frame-based animations for sprites. It supports
 * creating animations from texture atlases (tilesets) and provides methods
 * to update the animation over time.
 */
class Animation {
private:
    std::vector<primitives::IntRect> m_frames, m_rotated_frames;
    float m_current_frame, m_animation_speed;
    std::shared_ptr<primitives::Sprite> m_sprite;

public:
    Animation() = delete;

    /**
     * @brief Constructs an Animation object from a texture atlas.
     *
     * @param texture Reference to the texture containing the animation frames
     * @param x X coordinate of the first frame in the texture (in pixels)
     * @param y Y coordinate of the first frame in the texture (in pixels)
     * @param width Width of each frame (in pixels)
     * @param height Height of each frame (in pixels)
     * @param frames_count Total number of frames in the animation
     * @param animation_speed Speed of animation in frames per second
     * @param step Distance between frames in the texture atlas (in pixels)
     */
    Animation(const primitives::Texture& texture, int x, int y, int width, int height, int frames_count, float animation_speed, int step);
    ~Animation() = default;

    /**
     * @brief Updates the animation based on elapsed time.
     *
     * Advances the animation frame based on the time passed and returns
     * the sprite with the updated texture rectangle.
     *
     * @param time Elapsed time since last update
     * @param rotate Whether to use the rotated version of the frames
     * @return std::shared_ptr<sf::Sprite> Shared pointer to the sprite with updated animation frame
     */
    std::shared_ptr<primitives::Sprite> Tick(float time, bool rotate);
};

}
