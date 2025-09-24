#pragma once

#include <stdint.h>

namespace game_engine {
namespace primitives {

struct Color {
    uint8_t r = 0;
    uint8_t g = 0;
    uint8_t b = 0;
    uint8_t a = 255;

    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255) : r(r), g(g), b(b), a(a) {};
};

namespace colors {

static const Color Black = { 0, 0, 0, 255 };
static const Color White = { 255, 255, 255, 255 };
static const Color Red = { 255, 0, 0, 255 };
static const Color Green = { 0, 255, 0, 255 };
static const Color Blue = { 0, 0, 255, 255 };

}

}
}
