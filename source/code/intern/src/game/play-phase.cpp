#include "game/play-phase.hpp"
#include <iostream>

using namespace game;

// -----------------------------------------------------------------------------

PlayPhase::PlayPhase() {}
PlayPhase::~PlayPhase() {}

// -----------------------------------------------------------------------------

void PlayPhase::onEnter(sf::RenderWindow &window) {
    std::cout << "PlayPhase onEnter" << std::endl;
}

void PlayPhase::onLeave() { std::cout << "PlayPhase onLeave" << std::endl; }

PhaseKind::Enum PlayPhase::onRun() {
    std::cout << "PlayPhase onRun" << std::endl;
    return PhaseKind::UnloadMap;
}