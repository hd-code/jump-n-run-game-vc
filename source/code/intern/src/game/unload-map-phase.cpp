#include "game/unload-map-phase.hpp"

#include <iostream>

using namespace game;

// -----------------------------------------------------------------------------

UnloadMapPhase::UnloadMapPhase() {}
UnloadMapPhase::~UnloadMapPhase() {}

// -----------------------------------------------------------------------------

void UnloadMapPhase::onEnter() {
    std::cout << "UnloadMapPhase onEnter" << std::endl;
}

void UnloadMapPhase::onLeave() {
    std::cout << "UnloadMapPhase onLeave" << std::endl;
}

int UnloadMapPhase::onRun() {
    std::cout << "UnloadMapPhase onRun" << std::endl;
    return Phase::Shutdown;
}