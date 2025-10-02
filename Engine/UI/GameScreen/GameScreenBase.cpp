#include "GameScreenBase.h"

#include "Constants.h"

using namespace game_engine::ui;

GameScreenBase::GameScreenBase() {
    setZ(GAME_SCREEN_Z);
}

GameScreenBase::~GameScreenBase() {}

void GameScreenBase::showGameScreen() {
    setAllObjectsVisible(true);
}

void GameScreenBase::hideGameScreen() {
    setAllObjectsVisible(false);
}

void GameScreenBase::addObject(drawable_t object) {
    m_screenObjects.insert(std::make_pair(object, false));
}

void GameScreenBase::draw(const game_engine::primitives::RenderWindow& window) {
    for (const auto& pair : m_screenObjects) {
        if (pair.second) {
            window.draw(*pair.first);
        }
    }
}

void GameScreenBase::setAllObjectsVisible(bool visible) {
    for (auto& pair : m_screenObjects) {
        pair.second = visible;
    }
}
