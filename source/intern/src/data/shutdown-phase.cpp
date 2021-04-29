#include "data/shutdown-phase.hpp"
#include "data/event-system.hpp"
#include "data/meta-entity-system.hpp"

using namespace data;

// -----------------------------------------------------------------------------

ShutdownPhase::ShutdownPhase() {}

ShutdownPhase::~ShutdownPhase() {}

// -----------------------------------------------------------------------------

void ShutdownPhase::onEnter() {}

void ShutdownPhase::onLeave() {}

bool ShutdownPhase::onRun() {
    MetaEntitySystem::getInstance().clear();
    EventSystem::getInstance().fireEvent(EventKind::MetaEntities_clear);
    return false;
}