#include "data/map.hpp"
#include "core/aabb.hpp"
#include "core/vector2.hpp"
#include "data/entity-iterator.hpp"
#include "data/entity.hpp"
#include "data/sector.hpp"
#include <cmath>

using namespace data;

// -----------------------------------------------------------------------------

Map::Map(float width, float height)
    : numOfSectorsX_(calcNumOfSectors(width)),
      numOfSectorsY_(calcNumOfSectors(height)) {
    sectors_ = new Sector[numOfSectorsX_ * numOfSectorsY_];
}

Map::~Map() { delete[] sectors_; }

// -----------------------------------------------------------------------------

void Map::addEntity(Entity &entity) {
    getSector(entity.getPosition()).addEntity(entity);
}

void Map::removeEntity(Entity &entity) {
    getSector(entity.getPosition()).removeEntity(entity);
}

void Map::moveEntity(Entity &entity) {
    removeEntity(entity);
    addEntity(entity);
}

// -----------------------------------------------------------------------------

EntityIterator Map::begin(const core::AABB &aabb) {
    EntityIterator empty;

    auto sectorIndex = getFirstSectorIndex(aabb);
    auto lastSectorIndex = getLastSectorIndex(aabb);

    while (sectorIndex <= lastSectorIndex) {
        auto result = sectors_[sectorIndex].searchSector(aabb);
        if (result != empty) {
            return result;
        }
        sectorIndex = getNextSectorIndex(aabb, sectorIndex);
    }

    return empty;
}

EntityIterator Map::begin(const core::AABB &aabb, EntityKind::Enum kind) {
    EntityIterator empty;

    auto sectorIndex = getFirstSectorIndex(aabb);
    auto lastSectorIndex = getLastSectorIndex(aabb);

    while (sectorIndex <= lastSectorIndex) {
        auto result = sectors_[sectorIndex].searchSector(aabb, kind);
        if (result != empty) {
            return result;
        }
        sectorIndex = getNextSectorIndex(aabb, sectorIndex);
    }

    return empty;
}

// -----------------------------------------------------------------------------

EntityIterator Map::next(EntityIterator current, const core::AABB &aabb) {
    EntityIterator empty;

    auto sectorIndex = getSectorIndex(current->getPosition());
    auto lastSectorIndex = getLastSectorIndex(aabb);
    if (sectorIndex > lastSectorIndex) {
        return empty;
    }

    // search sector of current
    auto result = sectors_[sectorIndex].searchSector(current, aabb);
    if (result != empty) {
        return result;
    }

    // search following sectors
    sectorIndex = getNextSectorIndex(aabb, sectorIndex);
    while (sectorIndex <= lastSectorIndex) {
        result = sectors_[sectorIndex].searchSector(aabb);
        if (result != empty) {
            return result;
        }
        sectorIndex = getNextSectorIndex(aabb, sectorIndex);
    }

    return empty;
}

EntityIterator Map::next(EntityIterator current, const core::AABB &aabb,
                         EntityKind::Enum kind) {
    EntityIterator empty;

    auto sectorIndex = getSectorIndex(current->getPosition());
    auto lastSectorIndex = getLastSectorIndex(aabb);
    if (sectorIndex > lastSectorIndex) {
        return empty;
    }

    // search sector of current
    auto result = sectors_[sectorIndex].searchSector(current, aabb, kind);
    if (result != empty) {
        return result;
    }

    // search following sectors
    sectorIndex = getNextSectorIndex(aabb, sectorIndex);
    while (sectorIndex <= lastSectorIndex) {
        result = sectors_[sectorIndex].searchSector(aabb, kind);
        if (result != empty) {
            return result;
        }
        sectorIndex = getNextSectorIndex(aabb, sectorIndex);
    }

    return empty;
}

// -----------------------------------------------------------------------------

EntityIterator Map::end() { return EntityIterator(); }

// -----------------------------------------------------------------------------

Sector &Map::getSector(const core::Vector2 &position) {
    return sectors_[getSectorIndex(position)];
}

// -----------------------------------------------------------------------------

unsigned int Map::getSectorIndex(unsigned int x, unsigned int y) {
    return y * numOfSectorsX_ + x;
}

unsigned int Map::getSectorIndex(const core::Vector2 &position) {
    auto x = calcIndex(position.getX());
    auto y = calcIndex(position.getY());
    return getSectorIndex(x, y);
}

// -----------------------------------------------------------------------------

unsigned int Map::getFirstSectorIndex(const core::AABB &aabb) {
    return getSectorIndex(aabb.getMin());
}

unsigned int Map::getLastSectorIndex(const core::AABB &aabb) {
    return std::min(getSectorIndex(aabb.getMax()),
                    numOfSectorsX_ * numOfSectorsY_ - 1);
}

unsigned int Map::getNextSectorIndex(const core::AABB &aabb,
                                     unsigned int currentIndex) {
    auto x = currentIndex % numOfSectorsX_;
    auto y = (unsigned int)std::floor(currentIndex / numOfSectorsX_);

    x += 1;
    if (x > calcIndex(aabb.getMax().getX())) {
        x = calcIndex(aabb.getMin().getX());
        y += 1;
    }

    return getSectorIndex(x, y);
}

// -----------------------------------------------------------------------------

unsigned int Map::calcNumOfSectors(float widthOrHeight) {
    return (unsigned int)std::ceilf(widthOrHeight / Sector::size);
}

unsigned int Map::calcIndex(float xOrY) {
    return (unsigned int)std::floorf(xOrY / Sector::size);
}