#include "GameStateMachine.h"

using namespace game_engine;

GameStateMachine::GameStateMachine() {}

GameStateMachine::~GameStateMachine() {}

void GameStateMachine::setState(GameState newState) {
    m_prevState = m_currentState;
    m_currentState = newState;

    switch (m_currentState) {
        case GameState::MAIN_MENU:
            if (m_prevState != GameState::MAIN_MENU) {
                fireShowMainMenu();
            }
            break;
        case GameState::RUNNING:
            if (m_prevState == GameState::MAIN_MENU) {
                fireGameStarted();
            }
            else if (m_prevState == GameState::PAUSED) {
                fireGameResumed();
            }
            else if (m_prevState == GameState::GAME_OVER) {
                fireGameRestarted();
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
