#pragma once

#include "core/singleton.hpp"
#include "data/entity-kind.hpp"

// -----------------------------------------------------------------------------

namespace core {
class AABB;
}

namespace data {

class Entity;
class EntityIterator;
class Map;

class MapSystem : public core::Singleton<MapSystem> {
  public:
    void createMap(float width, float height);
    void destroyMap();

    void addEntity(Entity &entity);
    void removeEntity(Entity &entity);
    void moveEntity(Entity &entity);

    EntityIterator begin(core::AABB &aabb);
    EntityIterator begin(core::AABB &aabb, EntityKind::Enum kind);

    EntityIterator next(EntityIterator current, core::AABB &aabb);
    EntityIterator next(EntityIterator current, core::AABB &aabb,
                        EntityKind::Enum kind);

    EntityIterator end();

    core::AABB getMapSize();

  private:
    template <class T> friend class core::Singleton;
    MapSystem();
    ~MapSystem();

    Map *map_;
};

} // namespace data