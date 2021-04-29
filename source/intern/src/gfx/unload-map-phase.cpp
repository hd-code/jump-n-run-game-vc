#include "gfx/unload-map-phase.hpp"
#include "core/config.hpp"
#include "data/event-system.hpp"
#include "gfx/entity-facet-system.hpp"
#include <assert.h>

using namespace gfx;

// -----------------------------------------------------------------------------

UnloadMapPhase::UnloadMapPhase()
    : window_(nullptr), screenTexture_(), screen_() {}

UnloadMapPhase::~UnloadMapPhase() {}

// -----------------------------------------------------------------------------

void UnloadMapPhase::onEnter(sf::RenderWindow &window) {
    window_ = &window;
    data::EventSystem::getInstance().addEventListener(*this);

    std::string filepath = core::Config::screensDir + "unload-map.png";
    assert(screenTexture_.loadFromFile(filepath));
    screen_.setTexture(screenTexture_);
}

void UnloadMapPhase::onLeave() {
    data::EventSystem::getInstance().removeEventListener(*this);
}

// -----------------------------------------------------------------------------

void UnloadMapPhase::render() {
    window_->clear();
    window_->draw(screen_);
    window_->display();
}

// -----------------------------------------------------------------------------

void UnloadMapPhase::onEvent(const data::Event &event) {
    switch (event.getKind()) {
    case data::EventKind::Entities_clear:
        EntityFacetSystem::getInstance().clear();
        break;
    }
}