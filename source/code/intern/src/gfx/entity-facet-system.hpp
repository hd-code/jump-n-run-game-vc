#pragma once

#include "core/item-manager.hpp"
#include "core/singleton.hpp"
#include "gfx/entity-facet.hpp"

// -----------------------------------------------------------------------------

namespace gfx {

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

} // namespace gfx