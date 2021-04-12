
#pragma once

#include "data/entity-list.hpp"

namespace data {

class Entity;
class Sector;

class EntityFolder {
  public:
    EntityFolder(Sector *sector);
    ~EntityFolder();

    void add(Entity &entity);
    void remove(Entity &entity);

  private:
    Sector *sector;
    EntityList entities;
};

} // namespace data
