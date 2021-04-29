#include "data/unload-map-phase.hpp"
#include "data/entity-system.hpp"
#include "data/event-system.hpp"
#include "data/map-system.hpp"

using namespace data;

// -----------------------------------------------------------------------------

UnloadMapPhase::UnloadMapPhase() {}

UnloadMapPhase::~UnloadMapPhase() {}

// -----------------------------------------------------------------------------

void UnloadMapPhase::onEnter() {
    // TODO: get file handle for saving current game state
}

void UnloadMapPhase::onLeave() {
    // TODO: clear file handle
}

bool UnloadMapPhase::onRun() {
    MapSystem::getInstance().destroyMap();
    EntitySystem::getInstance().clear();
    EventSystem::getInstance().fireEvent(EventKind::Entities_clear);
    return false;
}