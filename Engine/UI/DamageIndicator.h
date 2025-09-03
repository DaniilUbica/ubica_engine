#pragma once

#include "Base/Drawable.h"

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
    static DamageIndicatorsHolder* m_instance;

    DamageIndicatorsHolder() = default;

    static DamageIndicatorsHolder* instance();

public:
    DamageIndicatorsHolder(const DamageIndicatorsHolder&) = delete;
    void operator=(const DamageIndicatorsHolder&) = delete;

    static void Update(float time);
    static void addIndicator(const sf::Vector2f& pos, int damage, float speed, damage_indicator::Direction direction, const sf::Font& font, uint size, const sf::Color& borderColor, const sf::Color& textColor);
};

class DamageIndicator : public Drawable, public sf::Drawable {
private:
    int m_damage = 0;
    float m_textSpeed = 0.f;
    bool m_stopped = false;

    damage_indicator::Direction m_textDirection;
    std::unique_ptr<sf::Text> m_damageText;
    std::unique_ptr<sf::Text> m_damageTextBorder;
    sf::Vector2f m_currentPos;
    sf::Vector2f m_startPos;
    sf::Font m_font;

    sf::Vector2f getTextBordersPos();

protected:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:
    DamageIndicator(const sf::Vector2f& pos, int damage, float speed, damage_indicator::Direction direction, const sf::Font& font, uint size, const sf::Color& borderColor, const sf::Color& textColor);
    ~DamageIndicator() {};

    void Update(float time);

    bool stopped() const { return m_stopped; };
};

}
}
