#pragma once

#include "core/aabb.hpp"
#include "core/uncopyable.hpp"
#include "core/vector2.hpp"
#include "data/entity-kind.hpp"
#include "data/entity-link.hpp"
#include "sahm/pool.h"

// -----------------------------------------------------------------------------

namespace data {

class MetaEntity;

struct EntityFacetKind {
    typedef enum {
        Gfx,
        Logic,
        Length,
    } Enum;
};

class Entity : private core::Uncopyable {
  public:
    typedef unsigned int Id;

    Id getId() const;
    EntityKind::Enum getKind() const;
    MetaEntity &getMetaEntity() const;

    core::Vector2 getPosition() const;
    core::AABB &getAABB();
    const core::AABB &getAABB() const;

    void *getFacet(EntityFacetKind::Enum kind);
    void registerFacet(EntityFacetKind::Enum kind, void *facet);

  private:
    template <class T, size_t S> friend class sahm::CPool;
    Entity();
    ~Entity();

    friend class EntitySystem;
    void setId(Id id);

    friend class LoadMapPhase;
    void init(MetaEntity &metaEntity, float x, float y);

    void setAABB(const core::Vector2 &position);
    void setAABB(float x, float y);

    friend class EntityList;
    friend class EntityLink;
    EntityLink link_;

    Id id_;
    MetaEntity *metaEntity_;
    core::AABB aabb_;
    void *facets_[EntityFacetKind::Length];
};

} // namespace data