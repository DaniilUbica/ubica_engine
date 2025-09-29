#pragma once

#include "Primitives/Sprite/Sprite.hpp"

namespace game_engine {

class TransformableObject {
public:
    TransformableObject();
    TransformableObject(const primitives::Vector2f& position, const primitives::Vector2f& size);
    TransformableObject(const primitives::FloatRect& bounds);
    TransformableObject(const primitives::Sprite& sprite);
    virtual ~TransformableObject();

    void setPosition(const primitives::Vector2f& pos) { m_pos = pos; };
    void setSize(const primitives::Vector2f& size) { m_size = size; };

    primitives::Vector2f getPosition() const { return m_pos; };
    primitives::Vector2f getSize() const { return m_size; };

protected:
    void init(const primitives::Vector2f& position, const primitives::Vector2f& size);
    void init(const primitives::FloatRect& bounds);
    void init(const primitives::Sprite& sprite);

    primitives::Vector2f m_pos = { 0.f, 0.f };
    primitives::Vector2f m_size = { 0.f, 0.f };

};

}
