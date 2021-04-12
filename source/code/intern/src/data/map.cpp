#include "data/map.hpp"

#include "data/entity-iterator.hpp"
#include "data/entity.hpp"
#include "data/sector.hpp"
#include <cmath>
#include <iostream>

using namespace data;

// -----------------------------------------------------------------------------

Map::Map(float width, float height)
    : numOfSectorsX(std::ceilf(width / Sector::size)),
      numOfSectorsY(std::ceilf(height / Sector::size)) {
    unsigned int numOfSectors = numOfSectorsX * numOfSectorsY;
    sectors = new Sector *[numOfSectors];
    for (auto i = 0; i < numOfSectors; ++i) {
        sectors[i] = new Sector();
    }
}

Map::~Map() {
    unsigned int numOfSectors = numOfSectorsX * numOfSectorsY;
    for (auto i = 0; i < numOfSectors; ++i) {
        delete sectors[i];
    }
    delete[] sectors;
}

// -----------------------------------------------------------------------------

void Map::addEntity(Entity &entity) {
    std::cout << "addEntity: ";
    entity.sayHello();
}

void Map::removeEntity(Entity &entity) {
    std::cout << "removeEntity: ";
    entity.sayHello();
}

void Map::moveEntity(Entity &entity) {
    std::cout << "moveEntity: ";
    entity.sayHello();
}

// -----------------------------------------------------------------------------

Sector *Map::getSector(unsigned int x, unsigned int y) {
    if (x > numOfSectorsX || y > numOfSectorsY) {
        return nullptr;
    }
    return sectors[x * numOfSectorsX + y];
}