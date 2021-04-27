#include "logic/play-phase.hpp"
#include "data/event-system.hpp"

using namespace logic;

// -----------------------------------------------------------------------------

PlayPhase::PlayPhase() : leaveLevel_(false) {}

PlayPhase::~PlayPhase() {}

// -----------------------------------------------------------------------------

void PlayPhase::onEnter() {
    data::EventSystem::getInstance().addEventListener(*this);
}

void PlayPhase::onLeave() {
    data::EventSystem::getInstance().removeEventListener(*this);
}

bool PlayPhase::onRun() { return !leaveLevel_; }

// -----------------------------------------------------------------------------

void PlayPhase::onEvent(const data::Event &event) {
    // register user input
    // react to creation/delete of entities
    switch (event.getKind()) {
    case data::EventKind::UserInput:
        switch (event.getData().key) {
        case core::UserInput::Escape:
            leaveLevel_ = true;
            break;
        }
        break;
    }
}