#include "game/startup-phase.hpp"
#include "data/startup-phase.hpp"
#include "gfx/startup-phase.hpp"
#include "logic/startup-phase.hpp"

using namespace game;

// -----------------------------------------------------------------------------

StartupPhase::StartupPhase() {}
StartupPhase::~StartupPhase() {}

// -----------------------------------------------------------------------------

void StartupPhase::onEnter(sf::RenderWindow &window) {
    clock_.restart();

    data::StartupPhase::getInstance().onEnter();
    gfx::StartupPhase::getInstance().onEnter(window);
    logic::StartupPhase::getInstance().onEnter();
}

void StartupPhase::onLeave() {
    data::StartupPhase::getInstance().onLeave();
    gfx::StartupPhase::getInstance().onLeave();
    logic::StartupPhase::getInstance().onLeave();
}

PhaseKind::Enum StartupPhase::onRun() {
    gfx::StartupPhase::getInstance().render();

    bool stay = data::StartupPhase::getInstance().onRun();

    auto time = clock_.getElapsedTime();
    if (time.asMilliseconds() < 2000) {
        stay = true;
    }

    return stay ? PhaseKind::Startup : PhaseKind::MainMenu;
}