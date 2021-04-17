#include "logic/shutdown-phase.hpp"

#include "core/event-system.hpp"

using namespace logic;

// -----------------------------------------------------------------------------

ShutdownPhase::ShutdownPhase() {}

ShutdownPhase::~ShutdownPhase() {}

// -----------------------------------------------------------------------------

void ShutdownPhase::onEnter() {
    core::EventSystem::getInstance().addEventListener(*this);
}

void ShutdownPhase::onLeave() {
    core::EventSystem::getInstance().removeEventListener(*this);
}

void ShutdownPhase::onRun() {}

// -----------------------------------------------------------------------------

void ShutdownPhase::onEvent(core::Event &event) {}
