#include "gfx/play-phase.hpp"

#include "core/event-system.hpp"

using namespace gfx;

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

void PlayPhase::render() {}

// -----------------------------------------------------------------------------

void PlayPhase::onEvent(core::Event &event) {}
