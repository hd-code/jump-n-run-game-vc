#include "gui/main-menu-phase.hpp"
#include "data/event-system.hpp"

using namespace gui;

// -----------------------------------------------------------------------------

MainMenuPhase::MainMenuPhase()
    : selectedLabel_(SelectedLabel::BeginGame), escapePressed_(false),
      enterPressed_(false) {}

MainMenuPhase::~MainMenuPhase() {}

// -----------------------------------------------------------------------------

void MainMenuPhase::onEnter() {
    selectedLabel_ = SelectedLabel::BeginGame;
    escapePressed_ = false;
    enterPressed_ = false;

    data::EventSystem::getInstance().addEventListener(*this);
}

void MainMenuPhase::onLeave() {
    data::EventSystem::getInstance().removeEventListener(*this);
}

// -----------------------------------------------------------------------------

void MainMenuPhase::onEvent(const data::Event &event) {
    switch (event.getKind()) {
    case data::EventKind::UserInput:
        switch (event.getData().key) {
        case core::UserInput::Escape:
            escapePressed_ = true;
            break;
        case core::UserInput::Enter:
            enterPressed_ = true;
            break;
        case core::UserInput::Up:
            selectedLabel_ = SelectedLabel::BeginGame;
            break;
        case core::UserInput::Down:
            selectedLabel_ = SelectedLabel::Exit;
            break;
        }
        break;
    }
}

// -----------------------------------------------------------------------------

SelectedLabel::Enum MainMenuPhase::getSelectedLabel() const {
    return selectedLabel_;
}

bool MainMenuPhase::beginGame() const {
    return enterPressed_ && selectedLabel_ == SelectedLabel::BeginGame;
}

bool MainMenuPhase::exit() const {
    return escapePressed_ ||
           enterPressed_ && selectedLabel_ == SelectedLabel::Exit;
}