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

class GameScreenManager : public cpplib::singletone_from_this<GameScreenManager> {
    friend class singletone_from_this<GameScreenManager>;

public:
    ~GameScreenManager();

    void addGameScreen(GameState state, game_screen_t screen);
    void Update(float time);

    void onGameOver();
    void onGameStarted();
    void onGamePaused();
    void onGameResumed();
    void onShowMainMenu();

private:
    GameScreenManager();

    void hideAllGameScreens();

    std::map<GameState, game_screen_t> m_gameScreens;
    std::list<nod::scoped_connection> m_stateMachineConnections;
};

}
}
