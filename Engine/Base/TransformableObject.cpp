#include "TransformableObject.h"

using namespace game_engine;

TransformableObject::TransformableObject() {}

TransformableObject::TransformableObject(const primitives::Vector2f& position, const primitives::Vector2f& size) {
    init(position, size);
}

TransformableObject::TransformableObject(const primitives::FloatRect& bounds) {
    init(bounds);
}

TransformableObject::TransformableObject(const primitives::Sprite& sprite) {
    init(sprite.getGlobalBounds());
}

TransformableObject::~TransformableObject() {}

void TransformableObject::init(const primitives::Vector2f& position, const primitives::Vector2f& size) {
    m_pos = position;
    m_size = size;
}

void TransformableObject::init(const primitives::FloatRect& bounds) {
    m_pos = bounds.getPosition();
    m_size = bounds.getSize();
}

void TransformableObject::init(const primitives::Sprite& sprite) {
    init(sprite.getGlobalBounds());
}
