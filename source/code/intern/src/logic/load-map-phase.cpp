#include "logic/load-map-phase.hpp"
#include "data/entity-system.hpp"
#include "data/event-system.hpp"
#include "logic/entity-facet-system.hpp"
#include "tinyxml2/tinyxml2.h"
#include <assert.h>

using namespace logic;

// -----------------------------------------------------------------------------

LoadMapPhase::LoadMapPhase() {}

LoadMapPhase::~LoadMapPhase() {}

// -----------------------------------------------------------------------------

void LoadMapPhase::onEnter() {
    data::EventSystem::getInstance().addEventListener(*this);
}

void LoadMapPhase::onLeave() {
    data::EventSystem::getInstance().removeEventListener(*this);
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

#pragma warning(disable : 4189)
void LoadMapPhase::loadEntity(tinyxml2::XMLElement *xml) {
    const char *name;
    xml->QueryStringAttribute("name", &name);
    auto &entity = data::EntitySystem::getInstance().get(name);

    auto &facet = EntityFacetSystem::getInstance().create(entity.getId());

    auto logicElement = xml->FirstChildElement("logic");
    assert(logicElement != nullptr);

    // Do stuff here...

    entity.registerFacet(data::EntityFacetKind::Logic, &facet);
}