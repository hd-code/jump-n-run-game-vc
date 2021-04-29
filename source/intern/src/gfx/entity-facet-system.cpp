#include "gfx/entity-facet-system.hpp"

using namespace gfx;

// -----------------------------------------------------------------------------

EntityFacetSystem::EntityFacetSystem() : itemManager_() {}

EntityFacetSystem::~EntityFacetSystem() {}

// -----------------------------------------------------------------------------

EntityFacet &EntityFacetSystem::create(Id id) {
    return itemManager_.create(id);
}

void EntityFacetSystem::destroy(Id id) { itemManager_.remove(id); }

// -----------------------------------------------------------------------------

void EntityFacetSystem::clear() { itemManager_.clear(); }