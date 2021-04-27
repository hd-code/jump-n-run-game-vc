#include "logic/startup-phase.hpp"
#include "data/event-system.hpp"
#include "data/meta-entity-system.hpp"
#include "logic/meta-entity-facet-system.hpp"
#include "tinyxml2/tinyxml2.h"
#include <assert.h>

using namespace logic;

// -----------------------------------------------------------------------------

StartupPhase::StartupPhase() {}

StartupPhase::~StartupPhase() {}

// -----------------------------------------------------------------------------

void StartupPhase::onEnter() {
    data::EventSystem::getInstance().addEventListener(*this);
}

void StartupPhase::onLeave() {
    data::EventSystem::getInstance().removeEventListener(*this);
}

// -----------------------------------------------------------------------------

void StartupPhase::onEvent(const data::Event &event) {
    switch (event.getKind()) {
    case data::EventKind::MetaEntity_load:
        loadMetaEntity(event.getData().xmlElement);
        break;
    }
}

// -----------------------------------------------------------------------------

void StartupPhase::loadMetaEntity(tinyxml2::XMLElement *xml) {
    const char *name;
    xml->QueryStringAttribute("name", &name);
    auto &metaEntity = data::MetaEntitySystem::getInstance().get(name);

    auto &facet =
        MetaEntityFacetSystem::getInstance().create(metaEntity.getId());

    auto logicElement = xml->FirstChildElement("logic");
    assert(logicElement != nullptr);

    // Do stuff here...

    metaEntity.registerFacet(data::MetaEntityFacetKind::Logic, &facet);
}