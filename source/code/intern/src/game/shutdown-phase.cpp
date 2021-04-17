#include "game/shutdown-phase.hpp"
#include <iostream>

using namespace game;

// -----------------------------------------------------------------------------

ShutdownPhase::ShutdownPhase() {}
ShutdownPhase::~ShutdownPhase() {}

// -----------------------------------------------------------------------------

void ShutdownPhase::onEnter() {
    std::cout << "ShutdownPhase onEnter" << std::endl;
}

void ShutdownPhase::onLeave() {
    std::cout << "ShutdownPhase onLeave" << std::endl;
}

PhaseKind::Enum ShutdownPhase::onRun() {
    std::cout << "ShutdownPhase onRun" << std::endl;
    return PhaseKind::Exit;
}