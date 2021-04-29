#include "data/entity-system.hpp"

using namespace data;

// -----------------------------------------------------------------------------

EntitySystem::EntitySystem() {}

EntitySystem::~EntitySystem() {}

// -----------------------------------------------------------------------------

Entity &EntitySystem::create(const std::string &name) {
    auto id = idManager_.add(name);
    auto &entity = itemManager_.create(id);
    entity.setId(id);
    return entity;
}

// -----------------------------------------------------------------------------

Entity &EntitySystem::get(const std::string &name) {
    auto id = idManager_.getId(name);
    return itemManager_.get(id);
}

Entity &EntitySystem::get(Entity::Id id) { return itemManager_.get(id); }

// -----------------------------------------------------------------------------

void EntitySystem::clear() {
    idManager_.clear();
    itemManager_.clear();
}