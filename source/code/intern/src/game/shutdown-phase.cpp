#include "game/shutdown-phase.hpp"
#include "data/shutdown-phase.hpp"
#include "gfx/shutdown-phase.hpp"
#include "logic/shutdown-phase.hpp"

using namespace game;

// -----------------------------------------------------------------------------

ShutdownPhase::ShutdownPhase() : shutdownFired_(false) {}

ShutdownPhase::~ShutdownPhase() {}

// -----------------------------------------------------------------------------

void ShutdownPhase::onEnter(sf::RenderWindow &window) {
    clock_.restart();

    data::ShutdownPhase::getInstance().onEnter();
    gfx::ShutdownPhase::getInstance().onEnter(window);
    logic::ShutdownPhase::getInstance().onEnter();
}

void ShutdownPhase::onLeave() {
    data::ShutdownPhase::getInstance().onLeave();
    gfx::ShutdownPhase::getInstance().onLeave();
    logic::ShutdownPhase::getInstance().onLeave();
}

PhaseKind::Enum ShutdownPhase::onRun() {
    gfx::ShutdownPhase::getInstance().render();

    bool stay = data::ShutdownPhase::getInstance().onRun();

    auto time = clock_.getElapsedTime();
    if (time.asMilliseconds() < 2000) {
        stay = true;
    }

    return stay ? PhaseKind::Shutdown : PhaseKind::Exit;
}