#pragma once

#include "Base/DrawableObject.h"

#include "Primitives/Font/Font.hpp"
#include "Primitives/Text/Text.hpp"

namespace game_engine {
namespace ui {

namespace damage_indicator {
    enum class Direction {
        FROM_BOTTOM_TO_TOP
    };
}

class DamageIndicator;

namespace {
    using indicator_t = std::unique_ptr<DamageIndicator>;
}

class DamageIndicatorsHolder {
private:
    static std::vector<indicator_t> m_indicators;

    DamageIndicatorsHolder() = default;

public:
    DamageIndicatorsHolder(const DamageIndicatorsHolder&) = delete;
    void operator=(const DamageIndicatorsHolder&) = delete;

    static void Update(float time);
    static void addIndicator(const primitives::Vector2f& pos, int damage, float speed, damage_indicator::Direction direction, const primitives::Font& font, unsigned int size, const primitives::Color& borderColor, const primitives::Color& textColor, std::weak_ptr<DrawableObject> parent);
};

class DamageIndicator : public DrawableObject {
private:
    int m_damage = 0;
    float m_textSpeed = 0.f;
    bool m_stopped = false;

    damage_indicator::Direction m_textDirection;
    std::unique_ptr<primitives::Text> m_damageText;
    std::unique_ptr<primitives::Text> m_damageTextBorder;
    primitives::Vector2f m_currentPos;
    primitives::Vector2f m_startPos;
    primitives::Font m_font;

    std::weak_ptr<DrawableObject> m_parent;

    primitives::Vector2f getTextBordersPos();

protected:
    void draw(const primitives::RenderWindow& window) override;

public:
    DamageIndicator(const primitives::Vector2f& pos, int damage, float speed, damage_indicator::Direction direction, const primitives::Font& font, unsigned int size, const primitives::Color& borderColor, const primitives::Color& textColor, std::weak_ptr<DrawableObject> parent);
    ~DamageIndicator() {};

    void Update(float time);

    bool stopped() const { return m_stopped; };
};

}
}
