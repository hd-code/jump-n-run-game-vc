#include "game/load-map-phase.hpp"
#include "data/load-map-phase.hpp"
#include "gfx/load-map-phase.hpp"
#include "logic/load-map-phase.hpp"

using namespace game;

// -----------------------------------------------------------------------------

LoadMapPhase::LoadMapPhase() {}
LoadMapPhase::~LoadMapPhase() {}

// -----------------------------------------------------------------------------

void LoadMapPhase::onEnter(sf::RenderWindow &window) {
    clock_.restart();

    data::LoadMapPhase::getInstance().onEnter();
    gfx::LoadMapPhase::getInstance().onEnter(window);
    logic::LoadMapPhase::getInstance().onEnter();
}

void LoadMapPhase::onLeave() {
    data::LoadMapPhase::getInstance().onLeave();
    gfx::LoadMapPhase::getInstance().onLeave();
    logic::LoadMapPhase::getInstance().onLeave();
}

PhaseKind::Enum LoadMapPhase::onRun() {
    gfx::LoadMapPhase::getInstance().render();

    bool stay = data::LoadMapPhase::getInstance().onRun();

    auto time = clock_.getElapsedTime();
    if (time.asMilliseconds() < 2000) {
        stay = true;
    }

    return stay ? PhaseKind::LoadMap : PhaseKind::Play;
}