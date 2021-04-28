#include "gfx/play-phase.hpp"
#include "core/aabb.hpp"
#include "data/entity-iterator.hpp"
#include "data/entity.hpp"
#include "data/event-system.hpp"
#include "data/map-system.hpp"
#include "gfx/entity-facet.hpp"
#include "logic/play-phase.hpp"

using namespace gfx;

// -----------------------------------------------------------------------------

PlayPhase::PlayPhase() : window_(nullptr), view_() {}

PlayPhase::~PlayPhase() {}

// -----------------------------------------------------------------------------

void PlayPhase::onEnter(sf::RenderWindow &window) {
    window_ = &window;
    data::EventSystem::getInstance().addEventListener(*this);

    // TODO: set camera size dynamically
    view_.setSize(8.0f, 6.0f);
}

void PlayPhase::onLeave() {
    window_->setView(window_->getDefaultView());
    data::EventSystem::getInstance().removeEventListener(*this);
}

// -----------------------------------------------------------------------------

void PlayPhase::render() {
    window_->clear();

    auto &cameraPos = logic::PlayPhase::getInstance().getCameraPosition();
    view_.setCenter(cameraPos.getX(), cameraPos.getY());
    window_->setView(view_);

    auto center = view_.getCenter();
    auto halfSize = view_.getSize() / 2.0f;
    core::AABB screen(center.x - halfSize.x, center.y - halfSize.y,
                      center.x + halfSize.x, center.y + halfSize.y);

    auto end = data::MapSystem::getInstance().end();
    auto it = data::MapSystem::getInstance().begin(screen);

    while (it != end) {
        auto facet = static_cast<EntityFacet *>(
            it->getFacet(data::EntityFacetKind::Gfx));
        window_->draw(facet->getSprite());

        it = data::MapSystem::getInstance().next(it, screen);
    }

    window_->display();
}

// -----------------------------------------------------------------------------

#pragma warning(disable : 4100)
void PlayPhase::onEvent(const data::Event &event) {
    // react to entity move
}