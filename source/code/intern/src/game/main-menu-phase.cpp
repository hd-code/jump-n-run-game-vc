#include "game/main-menu-phase.hpp"

#include <iostream>

using namespace game;

// -----------------------------------------------------------------------------

MainMenuPhase::MainMenuPhase() {}
MainMenuPhase::~MainMenuPhase() {}

// -----------------------------------------------------------------------------

void MainMenuPhase::onEnter() {
    std::cout << "MainMenuPhase onEnter" << std::endl;
}

void MainMenuPhase::onLeave() {
    std::cout << "MainMenuPhase onLeave" << std::endl;
}

int MainMenuPhase::onRun() {
    std::cout << "MainMenuPhase onRun" << std::endl;
    return Phase::LoadMap;
}