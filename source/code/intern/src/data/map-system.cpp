#include "data/map-system.hpp"

#include "core/aabb.hpp"
#include "data/entity-iterator.hpp"
#include "data/map.hpp"
#include <iostream>

using namespace data;

// -----------------------------------------------------------------------------

MapSystem::MapSystem() {}

MapSystem::~MapSystem() {
    if (map != nullptr) {
        delete map;
    }
}

// -----------------------------------------------------------------------------

void MapSystem::initMap(float width, float height) {
    if (map == nullptr) {
        destroyMap();
    }
    map = new Map(width, height);
}

void MapSystem::destroyMap() { delete map; }

// -----------------------------------------------------------------------------

void MapSystem::addEntity(Entity &entity) {
    assert(map != nullptr);
    map->addEntity(entity);
}

void MapSystem::removeEntity(Entity &entity) {
    assert(map != nullptr);
    map->removeEntity(entity);
}

void MapSystem::moveEntity(Entity &entity) {
    assert(map != nullptr);
    map->moveEntity(entity);
}

// -----------------------------------------------------------------------------

EntityIterator MapSystem::begin(core::AABB &aabb) { return end(); }

EntityIterator MapSystem::begin(core::AABB &aabb, int category) {
    return end();
}

// -----------------------------------------------------------------------------

EntityIterator MapSystem::next(EntityIterator current, core::AABB &aabb) {
    return end();
}

EntityIterator MapSystem::next(EntityIterator current, core::AABB &aabb,
                               int category) {
    return end();
}

// -----------------------------------------------------------------------------

EntityIterator MapSystem::end() { return EntityIterator(); }