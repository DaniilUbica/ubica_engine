#pragma once

#include <map>
#include <list>

#include "cpplib/singletone.hpp"

#include "GameStateMachine.h"
#include "GameScreenBase.h"

namespace game_engine {
namespace ui {

namespace {
    using game_screen_t = std::unique_ptr<GameScreenBase>;
}

class GameScreenManager {
public:
    GameScreenManager(std::shared_ptr<GameStateMachine> stateMachine);
    virtual ~GameScreenManager();

    virtual void addGameScreen(int state, game_screen_t screen);
    virtual void Update(float time);

private:
    void onGameOver();
    void onGameStarted();
    void onGamePaused();
    void onGameResumed();
    void onShowMainMenu();

protected:
    void hideAllGameScreens();

    std::shared_ptr<GameStateMachine> m_stateMachine;
    std::map<int, game_screen_t> m_gameScreens;
    std::list<nod::scoped_connection> m_stateMachineConnections;
};

}
}
