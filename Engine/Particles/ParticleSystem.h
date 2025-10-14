#pragma once

#include "Primitives/CircleShape/CircleShape.hpp"
#include "Primitives/RenderWindow/RenderWindow.hpp"
#include "Primitives/Texture/Texture.hpp"
#include "Primitives/Vector2.hpp"

#include "cpplib/singletone.hpp"

namespace game_engine {

/**
 * @class Particle
 * @brief Represents a single particle in a particle system.
 *
 * The Particle class manages the visual representation, movement, and lifetime
 * of an individual particle. Each particle has a circular shape, velocity, and
 * a lifetime that decreases over time.
 */
class Particle {
private:
    primitives::CircleShape m_shape;
    primitives::Vector2f    m_velocity;
    float           m_lifetime;
    
public:

    /**
     * @brief Constructs a Particle at the specified position with the given color.
     * @param pos The initial position of the particle
     * @param color The color of the particle
     */
    Particle(primitives::Vector2f pos, primitives::Color& color);

    /**
     * @brief Updates the particle's state based on elapsed time.
     * @param time Elapsed time since the last update
     *
     * Moves the particle according to its velocity and decreases its lifetime.
     */
    void Update(float time);
    
    primitives::CircleShape getShape() const { return m_shape; };
    float getLifetime() const { return m_lifetime; };
};

/**
 * @class ParticleSystem
 * @brief Singleton class that manages all particles in the game.
 *
 * The ParticleSystem is responsible for creating, updating, and rendering
 * particles. It implements the singleton pattern to ensure only one instance
 * exists throughout the game.
 */
class ParticleSystem : public game_engine::cpplib::singletone_from_this<ParticleSystem> {
private:
    std::vector<Particle>  m_particles;

public:
    /**
     * @brief Updates all particles in the system.
     * @param time Elapsed time since the last update
     *
     * Updates each particle's state and removes particles that have expired.
     */
    void Update(float time);

    /**
     * @brief Creates a bursting bubble particle effect at the specified position.
     * @param pos The position where the bubble burst effect should occur
     * @param texture The texture to take color for the bubble particles
     */
    void burstingBubble(primitives::Vector2f pos, const primitives::Texture& texture);

    /**
     * @brief Renders all particles to the specified window.
     * @param window The render window to draw particles on
     */
    void drawParticles(primitives::RenderWindow& window);
};

}
