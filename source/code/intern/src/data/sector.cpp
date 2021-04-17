#include "data/sector.hpp"
#include "core/aabb.hpp"
#include "data/entity-iterator.hpp"
#include "data/entity.hpp"
#include <assert.h>

using namespace data;

// -----------------------------------------------------------------------------

Sector::Sector() {}

Sector::~Sector() {}

// -----------------------------------------------------------------------------

void Sector::addEntity(Entity &entity) {
    getFolder(entity.getKind()).addEntity(entity);
}

void Sector::removeEntity(Entity &entity) {
    getFolder(entity.getKind()).removeEntity(entity);
}

// -----------------------------------------------------------------------------

EntityIterator Sector::searchSector(const core::AABB &aabb) {
    EntityIterator empty;
    // search for entity folder by folder
    for (auto kind = 0; kind < EntityKind::Length; ++kind) {
        auto result = searchSector(aabb, static_cast<EntityKind::Enum>(kind));
        if (result != empty) {
            return result;
        }
    }
    return empty;
}

EntityIterator Sector::searchSector(const core::AABB &aabb,
                                    EntityKind::Enum kind) {
    EntityList &list = getFolder(kind).getEntities();
    for (auto iterator = list.begin(), end = list.end(); iterator != end;
         ++iterator) {
        if (aabb.contains(iterator->getPosition())) {
            return iterator;
        }
    }
    return EntityIterator();
}

EntityIterator Sector::searchSector(EntityIterator current,
                                    const core::AABB &aabb) {
    auto result = searchFolder(current, aabb);
    if (result != EntityIterator()) {
        return result;
    }

    return searchNextFolders(current, aabb);
}

EntityIterator Sector::searchSector(EntityIterator current,
                                    const core::AABB &aabb,
                                    EntityKind::Enum kind) {
    auto currentKind = current->getKind();

    // do not search when current is in a later folder as the requested one
    if (currentKind > kind) {
        return EntityIterator();
    }

    if (currentKind == kind) {
        return searchFolder(current, aabb);
    }

    // search the requested folder
    return searchSector(aabb, kind);
}

// -----------------------------------------------------------------------------

EntityIterator Sector::searchFolder(EntityIterator current,
                                    const core::AABB &aabb) {
    auto end = getFolder(current->getKind()).getEntities().end();
    for (auto iterator = ++current; iterator != end; ++iterator) {
        if (aabb.contains(iterator->getPosition())) {
            return iterator;
        }
    }
    return EntityIterator();
}

EntityIterator Sector::searchNextFolders(EntityIterator current,
                                         const core::AABB &aabb) {
    EntityIterator empty;
    for (auto kind = current->getKind() + 1; kind < EntityKind::Length;
         ++kind) {
        auto result = searchSector(aabb, static_cast<EntityKind::Enum>(kind));
        if (result != empty) {
            return result;
        }
    }
    return empty;
}

// -----------------------------------------------------------------------------

EntityFolder &Sector::getFolder(const EntityKind::Enum kind) {
    return folders_[kind];
}

EntityFolder &Sector::getFolder(int kind) { return folders_[kind]; }