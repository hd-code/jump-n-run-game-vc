#include "game/play-phase.hpp"
#include "gfx/play-phase.hpp"
#include "logic/play-phase.hpp"

using namespace game;

// -----------------------------------------------------------------------------

PlayPhase::PlayPhase() {}
PlayPhase::~PlayPhase() {}

// -----------------------------------------------------------------------------

void PlayPhase::onEnter(sf::RenderWindow &window) {
    clock_.restart();
    gfx::PlayPhase::getInstance().onEnter(window);
    logic::PlayPhase::getInstance().onEnter();
}

void PlayPhase::onLeave() {
    gfx::PlayPhase::getInstance().onLeave();
    logic::PlayPhase::getInstance().onLeave();
}

PhaseKind::Enum PlayPhase::onRun() {
    gfx::PlayPhase::getInstance().render();

    auto time = clock_.getElapsedTime();
    if (time.asMilliseconds() >= timeBetweenTurns_) {
        clock_.restart();
        bool stay = logic::PlayPhase::getInstance().onRun();
        if (!stay) {
            return PhaseKind::UnloadMap;
        }
    }

    return PhaseKind::Play;
}