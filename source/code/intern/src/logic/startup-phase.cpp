#include "logic/startup-phase.hpp"

#include "core/event-system.hpp"

using namespace logic;

// -----------------------------------------------------------------------------

StartupPhase::StartupPhase() {}

StartupPhase::~StartupPhase() {}

// -----------------------------------------------------------------------------

void StartupPhase::onEnter() {
    core::EventSystem::getInstance().addEventListener(*this);
}

void StartupPhase::onLeave() {
    core::EventSystem::getInstance().removeEventListener(*this);
}

void StartupPhase::onRun() {}

// -----------------------------------------------------------------------------

void StartupPhase::onEvent(core::Event &event) {}
