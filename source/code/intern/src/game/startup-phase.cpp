#include "game/startup-phase.hpp"

#include <iostream>

using namespace game;

// -----------------------------------------------------------------------------

StartupPhase::StartupPhase() {}
StartupPhase::~StartupPhase() {}

// -----------------------------------------------------------------------------

void StartupPhase::onEnter() {
    std::cout << "StartupPhase onEnter" << std::endl;
}

void StartupPhase::onLeave() {
    std::cout << "StartupPhase onLeave" << std::endl;
}

int StartupPhase::onRun() {
    std::cout << "StartupPhase onRun" << std::endl;
    return Phase::MainMenu;
}