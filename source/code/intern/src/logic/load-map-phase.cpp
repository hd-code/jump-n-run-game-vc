#include "logic/load-map-phase.hpp"

#include "core/event-system.hpp"

using namespace logic;

// -----------------------------------------------------------------------------

LoadMapPhase::LoadMapPhase() {}

LoadMapPhase::~LoadMapPhase() {}

// -----------------------------------------------------------------------------

void LoadMapPhase::onEnter() {
    core::EventSystem::getInstance().addEventListener(*this);
}

void LoadMapPhase::onLeave() {
    core::EventSystem::getInstance().removeEventListener(*this);
}

void LoadMapPhase::onRun() {}

// -----------------------------------------------------------------------------

void LoadMapPhase::onEvent(core::Event &event) {}
