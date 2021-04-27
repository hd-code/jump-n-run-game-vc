#pragma once

#include "core/uncopyable.hpp"
#include "data/entity-kind.hpp"
#include "sahm/pool.h"

// -----------------------------------------------------------------------------

namespace data {

struct MetaEntityFacetKind {
    typedef enum {
        Gfx,
        Logic,
        Length,
    } Enum;
};

class MetaEntity : private core::Uncopyable {
  public:
    typedef unsigned int Id;

    Id getId() const;
    EntityKind::Enum getKind() const;

    float getHeight() const;
    float getWidth() const;

    void *getFacet(MetaEntityFacetKind::Enum kind);
    void registerFacet(MetaEntityFacetKind::Enum kind, void *facet);

  private:
    template <class T, size_t S> friend class sahm::CPool;
    MetaEntity();
    ~MetaEntity();

    friend class MetaEntitySystem;
    void setId(Id id);

    friend class StartupPhase;
    void init(EntityKind::Enum kind, float height, float width);

    Id id_;
    EntityKind::Enum kind_;
    float height_, width_;
    void *facets_[MetaEntityFacetKind::Length];
};

} // namespace data