#pragma once

#include "Primitives/RenderWindow/RenderWindow.hpp"

namespace game_engine {

class IGameManager {
public:
    virtual ~IGameManager() {};

    virtual void initGame() = 0;
    virtual void deinitGame() = 0;
    virtual void restartGame() = 0;

    virtual void Update(float time) = 0;
    virtual void handleEvent(std::unique_ptr<primitives::Event> event) = 0;
    virtual void drawGameObjects() = 0;
};

}
