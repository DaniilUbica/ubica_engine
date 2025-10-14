#pragma once

#include "Base/DrawableObject.h"
#include "RenderWindow/RenderWindow.hpp"

namespace game_engine {
namespace ui {

namespace {
    using drawable_t = std::shared_ptr<game_engine::primitives::Drawable>;
}

class GameScreenBase : public DrawableObject {
public:
    GameScreenBase();
    virtual ~GameScreenBase();

    virtual void showGameScreen();
    virtual void hideGameScreen();

    virtual void constructScreen() = 0;
    virtual void Update(float time) = 0;

    virtual void setAllScreenObjectsVisible(bool visible);
    
    virtual void draw(const primitives::RenderWindow& window) override;

protected:
    std::vector<std::pair<drawable_t, bool /* visible */>> m_primitivesDrawableObjects;
};

}
}
