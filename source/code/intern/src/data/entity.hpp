#pragma once

#include "data/entity-link.hpp"

#include <string>

// -----------------------------------------------------------------------------

namespace data {

class Entity {
  public:
    Entity(std::string name);
    ~Entity();

    void sayHello();

  private:
    friend class EntityList;
    friend class EntityLink;
    EntityLink link;

    std::string name;
};

} // namespace data