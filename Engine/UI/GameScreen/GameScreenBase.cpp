#include "GameScreenBase.h"

#include "Constants.h"

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
