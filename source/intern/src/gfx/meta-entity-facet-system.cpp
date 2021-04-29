#include "gfx/meta-entity-facet-system.hpp"

using namespace gfx;

// -----------------------------------------------------------------------------

MetaEntityFacetSystem::MetaEntityFacetSystem() : itemManager_() {}

MetaEntityFacetSystem::~MetaEntityFacetSystem() {}

// -----------------------------------------------------------------------------

MetaEntityFacet &MetaEntityFacetSystem::create(Id id) {
    return itemManager_.create(id);
}

void MetaEntityFacetSystem::destroy(Id id) { itemManager_.remove(id); }

// -----------------------------------------------------------------------------

void MetaEntityFacetSystem::clear() { itemManager_.clear(); }