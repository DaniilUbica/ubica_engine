#include "GameScreenManager.h"

using namespace game_engine;
using namespace ui;

GameScreenManager::GameScreenManager(std::shared_ptr<GameStateMachine> stateMachine) : m_stateMachine(stateMachine) {
    m_stateMachineConnections.push_back(m_stateMachine->fireGameOver.connect([this]() {
        onGameOver();
    }));
    m_stateMachineConnections.push_back(m_stateMachine->fireGameStarted.connect([this]() {
        onGameStarted();
    }));
    m_stateMachineConnections.push_back(m_stateMachine->fireGamePaused.connect([this]() {
        onGamePaused();
    }));
    m_stateMachineConnections.push_back(m_stateMachine->fireGameResumed.connect([this]() {
        onGameResumed();
    }));
    m_stateMachineConnections.push_back(m_stateMachine->fireShowMainMenu.connect([this]() {
        onShowMainMenu();
    }));
}

GameScreenManager::~GameScreenManager() {
    m_gameScreens.clear();
}

void GameScreenManager::addGameScreen(int state, game_screen_t screen) {
    m_gameScreens.insert(std::make_pair(state, std::move(screen)));
}

void GameScreenManager::Update(float time) {
    for (auto& pair : m_gameScreens) {
        pair.second->Update(time);
    }
}

void GameScreenManager::onGameOver() { 
    hideAllGameScreens();
    m_gameScreens[static_cast<int>(GameState::GAME_OVER)]->showGameScreen();
}

void GameScreenManager::onGameStarted() {
    hideAllGameScreens();
    m_gameScreens[static_cast<int>(GameState::RUNNING)]->showGameScreen();
}

void GameScreenManager::onGamePaused() {
    hideAllGameScreens();
//    m_gameScreens[static_cast<int>(GameState::PAUSED)]->showGameScreen(); // TODO: got no paused screen now
}

void GameScreenManager::onGameResumed() {
    hideAllGameScreens();
}

void GameScreenManager::onShowMainMenu() { 
    hideAllGameScreens();
    m_gameScreens[static_cast<int>(GameState::MAIN_MENU)]->showGameScreen();
}

void GameScreenManager::hideAllGameScreens() {
    for (auto& pair : m_gameScreens) {
        pair.second->hideGameScreen();
    }
}
