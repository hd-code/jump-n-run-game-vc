#include "data/map-system.hpp"
#include "core/aabb.hpp"
#include "data/entity-iterator.hpp"
#include "data/entity.hpp"
#include "data/map.hpp"
#include <assert.h>

using namespace data;

// -----------------------------------------------------------------------------

MapSystem::MapSystem() {}

MapSystem::~MapSystem() { destroyMap(); }

// -----------------------------------------------------------------------------

void MapSystem::createMap(float width, float height) {
    destroyMap();
    map_ = new Map(width, height);
}

void MapSystem::destroyMap() {
    if (map_ != nullptr) {
        delete map_;
        map_ = nullptr;
    }
}

// -----------------------------------------------------------------------------

void MapSystem::addEntity(Entity &entity) {
    assert(map_ != nullptr);
    map_->addEntity(entity);
}

void MapSystem::removeEntity(Entity &entity) {
    assert(map_ != nullptr);
    map_->removeEntity(entity);
}

void MapSystem::moveEntity(Entity &entity) {
    assert(map_ != nullptr);
    map_->moveEntity(entity);
}

// -----------------------------------------------------------------------------

EntityIterator MapSystem::begin(core::AABB &aabb) {
    if (map_ == nullptr) {
        return EntityIterator();
    }
    return map_->begin(aabb);
}

EntityIterator MapSystem::begin(core::AABB &aabb, EntityKind::Enum kind) {
    if (map_ == nullptr) {
        return EntityIterator();
    }
    return map_->begin(aabb, kind);
}

// -----------------------------------------------------------------------------

EntityIterator MapSystem::next(EntityIterator current, core::AABB &aabb) {
    if (map_ == nullptr) {
        return EntityIterator();
    }
    return map_->next(current, aabb);
}

EntityIterator MapSystem::next(EntityIterator current, core::AABB &aabb,
                               EntityKind::Enum kind) {
    if (map_ == nullptr) {
        return EntityIterator();
    }
    return map_->next(current, aabb, kind);
}

// -----------------------------------------------------------------------------

EntityIterator MapSystem::end() {
    if (map_ == nullptr) {
        return EntityIterator();
    }
    return map_->end();
}

// -----------------------------------------------------------------------------

core::AABB MapSystem::getMapSize() {
    if (map_ == nullptr) {
        return core::AABB();
    }
    return map_->getMapSize();
}