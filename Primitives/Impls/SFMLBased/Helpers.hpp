#pragma once

#include "Rect/Rect.hpp"
#include <SFML/Graphics.hpp>

namespace game_engine {
namespace primitives {

template<typename T>
static sf::Vector2<T> engineVector2ToSfVector2(const Vector2<T>& engineVec) {
    return { engineVec.x, engineVec.y };
}

template<typename T>
static Rect<T> sfRectToEngineRect(const sf::Rect<T>& sfRect) {
    return { sfRect.position.x, sfRect.position.y, sfRect.size.x, sfRect.size.y };
}

template<typename T>
static sf::Rect<T> engineRectToSfRect(const Rect<T>& engineRect) {
    return { engineVector2ToSfVector2(engineRect.getPosition()), engineVector2ToSfVector2(engineRect.getSize()) };
}

}
}
