
#pragma once

#include "data/entity-list.hpp"

namespace data {

class Entity;
class Sector;

class EntityFolder {
  public:
    EntityFolder();
    ~EntityFolder();

    EntityList &getEntities();

    void addEntity(Entity &entity);
    void removeEntity(Entity &entity);

  private:
    EntityList entities_;
};

} // namespace data
