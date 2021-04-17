#pragma once

#include "data/entity-kind.hpp"

// -----------------------------------------------------------------------------

namespace core {
class AABB;
class Vector2;
} // namespace core

namespace data {

class Entity;
class EntityIterator;
class Sector;

class Map {
  public:
    Map(float width, float height);
    ~Map();

    void addEntity(Entity &entity);
    void removeEntity(Entity &entity);
    void moveEntity(Entity &entity);

    EntityIterator begin(const core::AABB &aabb);
    EntityIterator begin(const core::AABB &aabb, EntityKind::Enum kind);

    EntityIterator next(EntityIterator current, const core::AABB &aabb);
    EntityIterator next(EntityIterator current, const core::AABB &aabb,
                        EntityKind::Enum kind);

    EntityIterator end();

  private:
    Sector &getSector(const core::Vector2 &position);

    unsigned int getSectorIndex(unsigned int x, unsigned int y);
    unsigned int getSectorIndex(const core::Vector2 &position);

    unsigned int getFirstSectorIndex(const core::AABB &aabb);
    unsigned int getLastSectorIndex(const core::AABB &aabb);
    unsigned int getNextSectorIndex(const core::AABB &aabb,
                                    unsigned int currentIndex);

    static unsigned int calcNumOfSectors(float widthOrHeight);
    static unsigned int calcIndex(float xOrY);

    unsigned int numOfSectorsX_;
    unsigned int numOfSectorsY_;
    Sector *sectors_;
};

} // namespace data