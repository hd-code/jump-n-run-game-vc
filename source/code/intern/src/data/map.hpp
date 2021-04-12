#pragma once

// -----------------------------------------------------------------------------

namespace core {
struct AABB;
}

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

    Sector *getSector(unsigned int x, unsigned int y);

  private:
    unsigned int numOfSectorsX;
    unsigned int numOfSectorsY;
    Sector **sectors;
};

} // namespace data