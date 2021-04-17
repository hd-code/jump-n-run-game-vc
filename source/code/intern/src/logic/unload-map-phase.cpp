#include "logic/unload-map-phase.hpp"

#include "core/event-system.hpp"

using namespace logic;

// -----------------------------------------------------------------------------

UnloadMapPhase::UnloadMapPhase() {}

UnloadMapPhase::~UnloadMapPhase() {}

// -----------------------------------------------------------------------------

void UnloadMapPhase::onEnter() {
    core::EventSystem::getInstance().addEventListener(*this);
}

void UnloadMapPhase::onLeave() {
    core::EventSystem::getInstance().removeEventListener(*this);
}

void UnloadMapPhase::onRun() {}

// -----------------------------------------------------------------------------

void UnloadMapPhase::onEvent(core::Event &event) {}
