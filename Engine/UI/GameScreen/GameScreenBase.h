#pragma once

#include "Base/DrawableObject.h"
#include "RenderWindow/RenderWindow.hpp"

namespace game_engine {
namespace ui {

class GameScreenBase : public DrawableObject {
public:
    GameScreenBase();
    virtual ~GameScreenBase();

    virtual void showGameScreen();
    virtual void hideGameScreen();

    virtual void constructScreen() = 0;
    virtual void setAllScreenObjectsVisible(bool visible) = 0;
};

}
}
