#include "data/meta-entity-system.hpp"

using namespace data;

// -----------------------------------------------------------------------------

MetaEntitySystem::MetaEntitySystem() : idManager_(), itemManager_() {}
MetaEntitySystem::~MetaEntitySystem() { clear(); }

// -----------------------------------------------------------------------------

MetaEntity &MetaEntitySystem::create(const std::string &name) {
    auto id = idManager_.add(name);
    auto &metaEntity = itemManager_.create(id);
    metaEntity.setId(id);
    return metaEntity;
}

// -----------------------------------------------------------------------------

MetaEntity &MetaEntitySystem::get(const std::string &name) {
    auto id = idManager_.getId(name);
    return itemManager_.get(id);
}

MetaEntity &MetaEntitySystem::get(MetaEntity::Id id) {
    return itemManager_.get(id);
}

// -----------------------------------------------------------------------------

void MetaEntitySystem::clear() {
    idManager_.clear();
    itemManager_.clear();
}