#include "gfx/load-map-phase.hpp"
#include "core/config.hpp"
#include "data/entity-system.hpp"
#include "data/event-system.hpp"
#include "data/meta-entity.hpp"
#include "gfx/entity-facet-system.hpp"
#include "gfx/meta-entity-facet.hpp"
#include "tinyxml2.h"
#include <assert.h>

using namespace gfx;

// -----------------------------------------------------------------------------

LoadMapPhase::LoadMapPhase() : window_(nullptr), screenTexture_(), screen_() {}

LoadMapPhase::~LoadMapPhase() {}

// -----------------------------------------------------------------------------

void LoadMapPhase::onEnter(sf::RenderWindow &window) {
    window_ = &window;
    data::EventSystem::getInstance().addEventListener(*this);

    std::string filepath = core::Config::screensDir + "load-map.png";
    assert(screenTexture_.loadFromFile(filepath));
    screen_.setTexture(screenTexture_);
}

void LoadMapPhase::onLeave() {
    data::EventSystem::getInstance().removeEventListener(*this);
}

// -----------------------------------------------------------------------------

void LoadMapPhase::render() {
    window_->clear();
    window_->draw(screen_);
    window_->display();
}

// -----------------------------------------------------------------------------

void LoadMapPhase::onEvent(const data::Event &event) {
    switch (event.getKind()) {
    case data::EventKind::Entity_load:
        loadEntity(event.getData().xmlElement);
        break;
    }
}

// -----------------------------------------------------------------------------

void LoadMapPhase::loadEntity(tinyxml2::XMLElement *xml) {
    const char *name;
    xml->QueryStringAttribute("name", &name);
    auto &entity = data::EntitySystem::getInstance().get(name);
    auto metaFacet = static_cast<MetaEntityFacet *>(
        entity.getMetaEntity().getFacet(data::MetaEntityFacetKind::Gfx));

    auto &facet = EntityFacetSystem::getInstance().create(entity.getId());

    facet.init(entity.getMetaEntity().getWidth(),
               entity.getMetaEntity().getHeight(), entity.getPosition(),
               metaFacet->getTexture());

    auto gfxElement = xml->FirstChildElement("graphics");
    assert(gfxElement != nullptr);

    // Do more stuff here...

    entity.registerFacet(data::EntityFacetKind::Gfx, &facet);
}