#pragma once

#include "core/vector2.hpp"
#include "data/entity-kind.hpp"
#include "data/entity-link.hpp"
#include <string>

// -----------------------------------------------------------------------------

namespace core {
class AABB;
class Vector2;
} // namespace core

namespace data {

class Entity {
  public:
    Entity(std::string name, EntityKind::Enum kind, core::Vector2 pos);
    ~Entity();

    core::Vector2 getPosition() const;
    EntityKind::Enum getKind() const;

    void sayHello();
    void sayLink();

  private:
    friend class EntityList;
    friend class EntityLink;
    EntityLink link_;

    std::string name_;
    EntityKind::Enum kind_;
    core::Vector2 pos_;
};

} // namespace data