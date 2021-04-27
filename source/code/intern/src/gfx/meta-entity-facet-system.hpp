#pragma once

#include "core/item-manager.hpp"
#include "core/singleton.hpp"
#include "gfx/meta-entity-facet.hpp"

// -----------------------------------------------------------------------------

namespace gfx {

class MetaEntityFacetSystem : public core::Singleton<MetaEntityFacetSystem> {
  public:
    typedef unsigned int Id;

    MetaEntityFacet &create(Id id);
    void destroy(Id id);

    void clear();

  private:
    template <class T> friend class core::Singleton;
    MetaEntityFacetSystem();
    ~MetaEntityFacetSystem();

    core::ItemManager<MetaEntityFacet> itemManager_;
};

} // namespace gfx