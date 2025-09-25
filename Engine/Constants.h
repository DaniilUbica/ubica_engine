#pragma once

#include "Primitives/Font/Font.hpp"

namespace game_engine {

const primitives::Font FONT = { "ByteBounce.ttf" };
const uint FONT_SIZE        = 26;

const float DAMAGE_INDICATOR_SPEED = 0.04f;

constexpr float PI = 3.14159265f;

constexpr float SPRITE_SIZE = 64.f;

constexpr float WORLD_HEIGHT = 1080.f;
constexpr float WORLD_WIDTH  = 1536.f;

constexpr float PARTICLE_RADIUS = 2.f;
constexpr float PARTICLE_SPEED  = 5.f;

constexpr int BURSTING_BUBBLE_PARTICLES_COUNT = 100;

constexpr int SPRITE_OBJECT_Z = 2;

}
