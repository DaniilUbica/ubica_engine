#include "GameStateMachine.h"

using namespace game_engine;

GameStateMachine::GameStateMachine() {}

GameStateMachine::~GameStateMachine() {}

void GameStateMachine::setState(int newState) {
    const auto gameState = static_cast<GameState>(newState);
    const auto prevGameState = static_cast<GameState>(m_currentState);
    m_prevState = m_currentState;
    m_currentState = newState;

    switch (gameState) {
        case GameState::MAIN_MENU:
            if (prevGameState != GameState::MAIN_MENU) {
                fireShowMainMenu();
            }
            break;
        case GameState::RUNNING:
            if (prevGameState == GameState::MAIN_MENU) {
                fireGameStarted();
            }
            else if (prevGameState == GameState::PAUSED) {
                fireGameResumed();
            }
            else if (prevGameState == GameState::GAME_OVER) {
                fireGameRestarted();
            }
            break;
        case GameState::PAUSED:
            if (prevGameState != GameState::PAUSED) {
                fireGamePaused();
            }
            break;
        case GameState::GAME_OVER:
            if (prevGameState != GameState::GAME_OVER) {
                fireGameOver();
            }
            break;
        default:
            break;
    }
}
