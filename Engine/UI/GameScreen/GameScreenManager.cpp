#include "GameScreenManager.h"

using namespace game_engine;
using namespace ui;

std::shared_ptr<GameScreenManager> GameScreenManager::instance() {
    if (const auto sp = s_instance.lock()) {
        return sp;
    }

    const auto sp = std::shared_ptr<GameScreenManager>(new GameScreenManager());
    s_instance = sp;

    return sp;
}

GameScreenManager::GameScreenManager() {
    m_stateMachineConnections.push_back(GameStateMachine::instance()->fireGameOver.connect([this]() {
        onGameOver();
    }));
    m_stateMachineConnections.push_back(GameStateMachine::instance()->fireGameStarted.connect([this]() {
        onGameStarted();
    }));
    m_stateMachineConnections.push_back(GameStateMachine::instance()->fireGamePaused.connect([this]() {
        onGamePaused();
    }));
    m_stateMachineConnections.push_back(GameStateMachine::instance()->fireGameResumed.connect([this]() {
        onGameResumed();
    }));
    m_stateMachineConnections.push_back(GameStateMachine::instance()->fireShowMainMenu.connect([this]() {
        onShowMainMenu();
    }));
}

GameScreenManager::~GameScreenManager() {
    m_gameScreens.clear();
}

void GameScreenManager::addGameScreen(GameState state, game_screen_t screen) { 
    m_gameScreens.insert(std::make_pair(state, std::move(screen)));
}

void GameScreenManager::Update(float time) {
    for (auto& pair : m_gameScreens) {
        pair.second->Update(time);
    }
}

void GameScreenManager::onGameOver() { 
    hideAllGameScreens();
    m_gameScreens[GameState::GAME_OVER]->showGameScreen();
}

void GameScreenManager::onGameStarted() {
    hideAllGameScreens();
    m_gameScreens[GameState::RUNNING]->showGameScreen();
}

void GameScreenManager::onGamePaused() {
    hideAllGameScreens();
//    m_gameScreens[GameState::PAUSED]->showGameScreen(); // TODO: got no paused screen now
}

void GameScreenManager::onGameResumed() {
    hideAllGameScreens();
}

void GameScreenManager::onShowMainMenu() { 
    hideAllGameScreens();
    m_gameScreens[GameState::MAIN_MENU]->showGameScreen();
}

void GameScreenManager::hideAllGameScreens() {
    for (auto& pair : m_gameScreens) {
        pair.second->hideGameScreen();
    }
}
