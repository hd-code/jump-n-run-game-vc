#include "logic/shutdown-phase.hpp"
#include "data/event-system.hpp"
#include "logic/meta-entity-facet-system.hpp"

using namespace logic;

// -----------------------------------------------------------------------------

ShutdownPhase::ShutdownPhase() {}

ShutdownPhase::~ShutdownPhase() {}

// -----------------------------------------------------------------------------

void ShutdownPhase::onEnter() {
    data::EventSystem::getInstance().addEventListener(*this);
}

void ShutdownPhase::onLeave() {
    data::EventSystem::getInstance().removeEventListener(*this);
}

// -----------------------------------------------------------------------------

void ShutdownPhase::onEvent(const data::Event &event) {
    switch (event.getKind()) {
    case data::EventKind::MetaEntities_clear:
        MetaEntityFacetSystem::getInstance().clear();
        break;
    }
}