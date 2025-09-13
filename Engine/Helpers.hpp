#pragma once

#include "Primitives/Texture/Texture.hpp"

namespace game_engine {

primitives::Color calculateAverageTextureColor(const primitives::Texture& texture) {
    primitives::Vector2u size = texture.getSize();
    unsigned int width = size.x;
    unsigned int height = size.y;

    primitives::Image image = texture.copyToImage();

    float redSum = 0;
    float greenSum = 0;
    float blueSum = 0;
    float alphaSum = 0;

    int pixelCount = width * height;

    for (unsigned int x = 0; x < width; ++x) {
        for (unsigned int y = 0; y < height; ++y) {
            primitives::Color color = image.getPixelColor({ x, y });
            if (color.a == 0) {
                pixelCount--;
                continue;
            }

            redSum += color.r;
            greenSum += color.g;
            blueSum += color.b;
            alphaSum += color.a;
        }
    }

    float avgRed = redSum / pixelCount;
    float avgGreen = greenSum / pixelCount;
    float avgBlue = blueSum / pixelCount;
    float avgAlpha = alphaSum / pixelCount;

    return primitives::Color(avgRed, avgGreen, avgBlue, avgAlpha);
}

}
