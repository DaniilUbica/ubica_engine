#pragma once

#include "nod/nod.hpp"

#include "cpplib/singletone.hpp"

namespace game_engine {

enum class GameState {
    MAIN_MENU = 0,
    RUNNING,
    PAUSED,
    GAME_OVER,
    GAME_STATES_SIZE = 4
};

class GameStateMachine {
public:
    GameStateMachine();
    virtual ~GameStateMachine();

    virtual void setState(int newState);

    int currentState() const { return static_cast<int>(m_currentState); };

    nod::signal<void()> fireGameStarted;
    nod::signal<void()> fireGameResumed;
    nod::signal<void()> fireGamePaused;
    nod::signal<void()> fireGameRestarted;
    nod::signal<void()> fireGameOver;
    nod::signal<void()> fireShowMainMenu;

protected:
    int m_currentState = 0;
    int m_prevState    = 0;
};

}
