#pragma once

#include <map>
#include <list>

#include "GameStateMachine.h"
#include "GameScreenBase.h"

namespace game_engine {
namespace ui {

namespace {
    using game_screen_t = std::unique_ptr<GameScreenBase>;
}

class GameScreenManager {
public:
    static std::shared_ptr<GameScreenManager> instance();

    void addGameScreen(GameState state, game_screen_t screen);

    void onGameOver();
    void onGameStarted();
    void onGamePaused();
    void onGameResumed();
    void onShowMainMenu();

private:
    GameScreenManager();
    GameScreenManager(const GameScreenManager&) = delete;
    void operator=(const GameScreenManager&) = delete;

    void hideAllGameScreens();

    inline static std::weak_ptr<GameScreenManager> s_instance;

    std::map<GameState, game_screen_t> m_gameScreens;
    std::list<nod::scoped_connection> m_stateMachineConnections;
};

}
}
