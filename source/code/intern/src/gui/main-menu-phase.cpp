#include "gui/main-menu-phase.hpp"

#include "core/event-system.hpp"
#include "game/base-phase.hpp"

using namespace gui;

// -----------------------------------------------------------------------------

MainMenuPhase::MainMenuPhase()
    : selectedLabel(0), arrowUpPressed(false), arrowDownPressed(false) {}

MainMenuPhase::~MainMenuPhase() {}

// -----------------------------------------------------------------------------

int MainMenuPhase::getSelectedLabel() const { return selectedLabel; }

// -----------------------------------------------------------------------------

void MainMenuPhase::onEnter() {
    core::EventSystem::getInstance().addEventListener(*this);
}

void MainMenuPhase::onLeave() {
    core::EventSystem::getInstance().removeEventListener(*this);
}

int MainMenuPhase::onRun() {
    if (arrowUpPressed) {
        selectedLabel = 0;
    }

    if (arrowDownPressed) {
        selectedLabel = 1;
    }

    arrowUpPressed = false;
    arrowDownPressed = false;

    return game::PhaseKind::MainMenu;
}

// -----------------------------------------------------------------------------

void MainMenuPhase::onEvent(core::Event &event) {
    // if key event up => arrowUpPressed = true
    // if key event down => arrowDownPressed = true
}