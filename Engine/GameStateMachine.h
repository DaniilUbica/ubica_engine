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

class GameStateMachine : public game_engine::cpplib::singletone_from_this<GameStateMachine> {
    friend class singletone_from_this<GameStateMachine>;
public:
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
    GameStateMachine();

    GameState m_currentState = GameState::MAIN_MENU;
    GameState m_prevState    = GameState::MAIN_MENU;
};

}
