#include "gfx/shutdown-phase.hpp"
#include "core/config.hpp"
#include "data/event-system.hpp"
#include "gfx/meta-entity-facet-system.hpp"
#include <assert.h>

using namespace gfx;

// -----------------------------------------------------------------------------

ShutdownPhase::ShutdownPhase()
    : window_(nullptr), screenTexture_(), screen_() {}

ShutdownPhase::~ShutdownPhase() {}

// -----------------------------------------------------------------------------

void ShutdownPhase::onEnter(sf::RenderWindow &window) {
    window_ = &window;
    data::EventSystem::getInstance().addEventListener(*this);

    std::string filepath = core::Config::screensDir + "shutdown.png";
    assert(screenTexture_.loadFromFile(filepath));
    screen_.setTexture(screenTexture_);
}

void ShutdownPhase::onLeave() {
    data::EventSystem::getInstance().removeEventListener(*this);
}

// -----------------------------------------------------------------------------

void ShutdownPhase::render() {
    window_->clear();
    window_->draw(screen_);
    window_->display();
}

// -----------------------------------------------------------------------------

void ShutdownPhase::onEvent(const data::Event &event) {
    switch (event.getKind()) {
    case data::EventKind::MetaEntities_clear:
        MetaEntityFacetSystem::getInstance().clear();
        break;
    }
}