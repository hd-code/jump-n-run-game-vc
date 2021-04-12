#pragma once

#include "data/entity-link.hpp"
// #include "data/entity.hpp"

namespace data {

class Entity;

class EntityList {
  public:
    EntityList();
    ~EntityList();

    bool isEmpty() const;

    void push(Entity &entity);
    Entity &pop();

    void remove(Entity &entity);
    void clear();

  private:
    EntityLink anchor;
};

} // namespace data