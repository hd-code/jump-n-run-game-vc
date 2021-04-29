#pragma once

#include "data/entity-link.hpp"

namespace data {

class Entity;
class EntityIterator;

class EntityList {
  public:
    EntityList();
    ~EntityList();

    bool empty() const;

    void push_back(Entity &entity);
    Entity &pop_back();

    void remove(Entity &entity);
    void clear();

    EntityIterator begin();
    EntityIterator end();

  private:
    EntityLink anchor_;
};

} // namespace data