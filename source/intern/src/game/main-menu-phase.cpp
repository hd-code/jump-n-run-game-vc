#include "game/main-menu-phase.hpp"
#include "gfx/main-menu-phase.hpp"
#include "gui/main-menu-phase.hpp"

using namespace game;

// -----------------------------------------------------------------------------

MainMenuPhase::MainMenuPhase() {}

MainMenuPhase::~MainMenuPhase() {}

// -----------------------------------------------------------------------------

void MainMenuPhase::onEnter(sf::RenderWindow &window) {
    gfx::MainMenuPhase::getInstance().onEnter(window);
    gui::MainMenuPhase::getInstance().onEnter();
}

void MainMenuPhase::onLeave() {
    gfx::MainMenuPhase::getInstance().onLeave();
    gui::MainMenuPhase::getInstance().onLeave();
}

PhaseKind::Enum MainMenuPhase::onRun() {
    gfx::MainMenuPhase::getInstance().render();

    if (gui::MainMenuPhase::getInstance().exit()) {
        return PhaseKind::Shutdown;
    }

    if (gui::MainMenuPhase::getInstance().beginGame()) {
        return PhaseKind::LoadMap;
    }

    return PhaseKind::MainMenu;
}