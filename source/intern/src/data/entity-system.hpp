#pragma once

#include "core/id-manager.hpp"
#include "core/item-manager.hpp"
#include "core/singleton.hpp"
#include "data/entity.hpp"

// -----------------------------------------------------------------------------

namespace data {

class EntitySystem : public core::Singleton<EntitySystem> {
  public:
    Entity &create(const std::string &name);

    Entity &get(const std::string &name);
    Entity &get(Entity::Id id);

    void clear();

  private:
    template <class T> friend class core::Singleton;
    EntitySystem();
    ~EntitySystem();

    core::IdManager idManager_;
    core::ItemManager<Entity> itemManager_;
};

} // namespace data