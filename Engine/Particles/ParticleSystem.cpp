#include "ParticleSystem.h"
#include "Constants.h"
#include "Helpers.hpp"

#include <cmath>

using namespace game_engine;

Particle::Particle(primitives::Vector2f pos, primitives::Color& color) {
    m_shape.setPosition({ pos.x, pos.y });
	m_shape.setRadius(PARTICLE_RADIUS);
	m_shape.setFillColor(color);

	float angle = static_cast<float>(std::rand()) / RAND_MAX * 2 * PI;
	float speed = static_cast<float>(std::rand()) / RAND_MAX * 100.0f;
	m_velocity = primitives::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);

	m_lifetime = 1.0f;
}

void Particle::Update(float time) { 
	m_shape.move(m_velocity * time);
	m_lifetime -= time;

	primitives::Color color = m_shape.getFillColor();
	color.a = static_cast<uint8_t>(255 * (m_lifetime / 1.0f));
	m_shape.setFillColor(color);
}

std::shared_ptr<ParticleSystem> ParticleSystem::instance() {
    if (const auto sp = m_instance.lock()) {
        return sp;
    }

    const auto sp = std::shared_ptr<ParticleSystem>(new ParticleSystem());
    m_instance = sp;

    return sp;
}

void ParticleSystem::Update(float time) {
    for (auto& particle : m_particles) {
        particle.Update(time);
    }

    m_particles.erase(std::remove_if(m_particles.begin(), m_particles.end(),
                       [](const Particle& particle) {
                           return particle.getLifetime() <= 0.0f;
                       }), m_particles.end());
}

void ParticleSystem::burstingBubble(primitives::Vector2f pos, const primitives::Texture& texture) {
	auto particle_color = calculateAverageTextureColor(texture);

	for (int i = 0; i < BURSTING_BUBBLE_PARTICLES_COUNT; i++) {
		m_particles.emplace_back(pos, particle_color);
	}
}

void ParticleSystem::drawParticles(primitives::RenderWindow& window) {
	for (auto& particle : m_particles) {
		window.draw(particle.getShape());
	}
}
