#include "game/load-map-phase.hpp"
#include <iostream>

using namespace game;

// -----------------------------------------------------------------------------

LoadMapPhase::LoadMapPhase() {}
LoadMapPhase::~LoadMapPhase() {}

// -----------------------------------------------------------------------------

void LoadMapPhase::onEnter() {
    std::cout << "LoadMapPhase onEnter" << std::endl;
}

void LoadMapPhase::onLeave() {
    std::cout << "LoadMapPhase onLeave" << std::endl;
}

PhaseKind::Enum LoadMapPhase::onRun() {
    std::cout << "LoadMapPhase onRun" << std::endl;
    return PhaseKind::Play;
}