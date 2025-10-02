#pragma once

#include <map>

#include "Base/DrawableObject.h"
#include "RenderWindow/RenderWindow.hpp"

namespace game_engine {
namespace ui {

namespace {
    using drawable_t = std::shared_ptr<primitives::Drawable>;
}

class GameScreenBase : public DrawableObject {
public:
    GameScreenBase();
    virtual ~GameScreenBase();

    virtual void showGameScreen();
    virtual void hideGameScreen();
    virtual void addObject(drawable_t object);

protected:
    void draw(const game_engine::primitives::RenderWindow& window);

    std::map<drawable_t, bool /* visible */> m_screenObjects;

private:
    void setAllObjectsVisible(bool visible);
};

}
}
