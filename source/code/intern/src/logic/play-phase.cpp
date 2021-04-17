#include "logic/play-phase.hpp"

#include "core/event-system.hpp"

using namespace logic;

// -----------------------------------------------------------------------------

PlayPhase::PlayPhase() {}

PlayPhase::~PlayPhase() {}

// -----------------------------------------------------------------------------

void PlayPhase::onEnter() {
    core::EventSystem::getInstance().addEventListener(*this);
}

void PlayPhase::onLeave() {
    core::EventSystem::getInstance().removeEventListener(*this);
}

void PlayPhase::onRun() {}

// -----------------------------------------------------------------------------

void PlayPhase::onEvent(core::Event &event) {}
