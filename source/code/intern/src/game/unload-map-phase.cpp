#include "game/unload-map-phase.hpp"
#include "core/config.hpp"
#include "data/unload-map-phase.hpp"
#include "gfx/unload-map-phase.hpp"
#include "logic/unload-map-phase.hpp"

using namespace game;

// -----------------------------------------------------------------------------

UnloadMapPhase::UnloadMapPhase() {}

UnloadMapPhase::~UnloadMapPhase() {}

// -----------------------------------------------------------------------------

void UnloadMapPhase::onEnter(sf::RenderWindow &window) {
    clock_.restart();

    data::UnloadMapPhase::getInstance().onEnter();
    gfx::UnloadMapPhase::getInstance().onEnter(window);
    logic::UnloadMapPhase::getInstance().onEnter();
}

void UnloadMapPhase::onLeave() {
    data::UnloadMapPhase::getInstance().onLeave();
    gfx::UnloadMapPhase::getInstance().onLeave();
    logic::UnloadMapPhase::getInstance().onLeave();
}

PhaseKind::Enum UnloadMapPhase::onRun() {
    gfx::UnloadMapPhase::getInstance().render();

    bool stay = data::UnloadMapPhase::getInstance().onRun();

    auto time = clock_.getElapsedTime();
    if (time.asMilliseconds() < core::Config::minLoadingTime) {
        stay = true;
    }

    return stay ? PhaseKind::UnloadMap : PhaseKind::MainMenu;
}