#pragma once

#include "core/singleton.hpp"

// -----------------------------------------------------------------------------

namespace core {
struct AABB;
}

namespace data {

class Entity;
class EntityIterator;
class Map;
class Sector;

class MapSystem : public core::Singleton<MapSystem> {
  public:
    void initMap(float width, float height);
    void destroyMap();

    void addEntity(Entity &entity);
    void removeEntity(Entity &entity);
    void moveEntity(Entity &entity);

    EntityIterator begin(core::AABB &aabb);
    EntityIterator begin(core::AABB &aabb, int category);

    EntityIterator next(EntityIterator current, core::AABB &aabb);
    EntityIterator next(EntityIterator current, core::AABB &aabb, int category);

    EntityIterator end();

  private:
    template <class T> friend class core::Singleton;
    MapSystem();
    ~MapSystem();

    Map *map;
};

} // namespace data