#include "GameScreenBase.h"

#include "Constants.h"

using namespace game_engine;
using namespace game_engine::ui;

GameScreenBase::GameScreenBase() {
    setZ(GAME_SCREEN_Z);
}

GameScreenBase::~GameScreenBase() {}

void GameScreenBase::showGameScreen() {
    constructScreen();
    setAllScreenObjectsVisible(true);
}

void GameScreenBase::hideGameScreen() {
    setAllScreenObjectsVisible(false);
}

void GameScreenBase::setAllScreenObjectsVisible(bool visible) {
    for (auto& pair : m_primitivesDrawableObjects) {
        pair.second = visible;
    }
}

void GameScreenBase::draw(const primitives::RenderWindow& window) {
    for (auto& pair : m_primitivesDrawableObjects) {
        pair.first->draw(window);
    }
}
