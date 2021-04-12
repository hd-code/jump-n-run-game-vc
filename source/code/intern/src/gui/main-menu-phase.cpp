#include "gui/main-menu-phase.hpp"

#include "data/event-system.hpp"
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
    data::EventSystem::getInstance().addEventListener(*this);
}

void MainMenuPhase::onLeave() {
    data::EventSystem::getInstance().removeEventListener(*this);
}

int MainMenuPhase::onRun() {
    if (arrowUpPressed) {
        selectedLabel = 0;
    }

    if (arrowDownPressed) {
        selectedLabel = 1;
    }

    return game::Phase::MainMenu;
}

// -----------------------------------------------------------------------------

void MainMenuPhase::onEvent(data::Event &event) {}