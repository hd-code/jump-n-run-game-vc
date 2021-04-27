#pragma once

#include "core/item-manager.hpp"
#include "core/singleton.hpp"
#include "logic/entity-facet.hpp"

// -----------------------------------------------------------------------------

namespace logic {

class EntityFacetSystem : public core::Singleton<EntityFacetSystem> {
  public:
    typedef unsigned int Id;

    EntityFacet &create(Id id);
    void destroy(Id id);

    void clear();

  private:
    template <class T> friend class core::Singleton;
    EntityFacetSystem();
    ~EntityFacetSystem();

    core::ItemManager<EntityFacet> itemManager_;
};

} // namespace logic