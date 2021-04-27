#include "logic/unload-map-phase.hpp"
#include "data/event-system.hpp"
#include "logic/entity-facet-system.hpp"

using namespace logic;

// -----------------------------------------------------------------------------

UnloadMapPhase::UnloadMapPhase() {}

UnloadMapPhase::~UnloadMapPhase() {}

// -----------------------------------------------------------------------------

void UnloadMapPhase::onEnter() {
    data::EventSystem::getInstance().addEventListener(*this);
}

void UnloadMapPhase::onLeave() {
    data::EventSystem::getInstance().removeEventListener(*this);
}

// -----------------------------------------------------------------------------

void UnloadMapPhase::onEvent(const data::Event &event) {
    switch (event.getKind()) {
    case data::EventKind::Entities_clear:
        EntityFacetSystem::getInstance().clear();
        break;
    }
}