#include "gfx/play-phase.hpp"
#include "data/event-system.hpp"

using namespace gfx;

// -----------------------------------------------------------------------------

PlayPhase::PlayPhase() : window_(nullptr) {}

PlayPhase::~PlayPhase() {}

// -----------------------------------------------------------------------------

void PlayPhase::onEnter(sf::RenderWindow &window) {
    window_ = &window;
    data::EventSystem::getInstance().addEventListener(*this);
}

void PlayPhase::onLeave() {
    data::EventSystem::getInstance().removeEventListener(*this);
}

// -----------------------------------------------------------------------------

void PlayPhase::render() {}

// -----------------------------------------------------------------------------

void PlayPhase::onEvent(const data::Event &event) {
    // react to entity move
}
