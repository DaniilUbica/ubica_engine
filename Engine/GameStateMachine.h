#pragma once

#include "nod/nod.hpp"

#include "cpplib/singletone.hpp"

namespace game_engine {

enum class GameState {
    MAIN_MENU = 0,
    RUNNING,
    PAUSED,
    GAME_OVER
};

class GameStateMachine {
public:
    GameStateMachine();
    ~GameStateMachine();

    void setState(GameState newState);

    GameState currentState() const { return m_currentState; };

    nod::signal<void()> fireGameStarted;
    nod::signal<void()> fireGameResumed;
    nod::signal<void()> fireGamePaused;
    nod::signal<void()> fireGameRestarted;
    nod::signal<void()> fireGameOver;
    nod::signal<void()> fireShowMainMenu;

private:
    GameState m_currentState = GameState::MAIN_MENU;
    GameState m_prevState    = GameState::MAIN_MENU;
};

}
