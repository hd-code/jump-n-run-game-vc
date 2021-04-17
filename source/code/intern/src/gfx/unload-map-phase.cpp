#include "gfx/unload-map-phase.hpp"

#include "core/event-system.hpp"

using namespace gfx;

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

// -----------------------------------------------------------------------------

void UnloadMapPhase::render() {}

// -----------------------------------------------------------------------------

void UnloadMapPhase::onEvent(core::Event &event) {}
