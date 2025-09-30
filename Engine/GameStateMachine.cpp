#include "GameStateMachine.h"

using namespace game_engine;

std::shared_ptr<GameStateMachine> GameStateMachine::instance() {
    if (const auto sp = s_instance.lock()) {
        return sp;
    }

    const auto sp = std::shared_ptr<GameStateMachine>(new GameStateMachine());
    s_instance = sp;

    return sp;
}

GameStateMachine::GameStateMachine() {}

GameStateMachine::~GameStateMachine() {}

void GameStateMachine::setState(GameState newState) {
    m_prevState = m_currentState;
    m_currentState = newState;

    switch (m_currentState) {
        case GameState::MAIN_MENU:
            break;
        case GameState::RUNNING:
            if (m_prevState != GameState::RUNNING && m_prevState == GameState::MAIN_MENU) {
                fireGameStarted();
            }
            else if (m_prevState != GameState::RUNNING && m_prevState == GameState::PAUSED) {
                fireGameResumed();
            }
            break;
        case GameState::PAUSED:
            if (m_prevState != GameState::PAUSED) {
                fireGamePaused();
            }
            break;
        case GameState::GAME_OVER:
            if (m_prevState != GameState::GAME_OVER) {
                fireGameOver();
            }
            break;
        default:
            break;
    }
}
