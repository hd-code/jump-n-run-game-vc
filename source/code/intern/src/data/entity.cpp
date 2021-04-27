#include "data/entity.hpp"
#include "core/aabb.hpp"
#include "data/meta-entity.hpp"
#include <iostream>

using namespace data;

// -----------------------------------------------------------------------------

Entity::Entity() : id_(), metaEntity_(nullptr), aabb_() {}

Entity::~Entity() {}

void Entity::setId(Id id) { id_ = id; }

void Entity::init(MetaEntity &metaEntity, float x, float y) {
    metaEntity_ = &metaEntity;
    setAABB(x, y);
}

// -----------------------------------------------------------------------------

Entity::Id Entity::getId() const { return id_; }
EntityKind::Enum Entity::getKind() const { return metaEntity_->getKind(); }

// -----------------------------------------------------------------------------

core::Vector2 Entity::getPosition() const { return aabb_.getCenter(); }

core::AABB &Entity::getAABB() { return aabb_; }
const core::AABB &Entity::getAABB() const { return aabb_; }

// -----------------------------------------------------------------------------

void *Entity::getFacet(EntityFacetKind::Enum kind) { return facets_[kind]; }

void Entity::registerFacet(EntityFacetKind::Enum kind, void *facet) {
    facets_[kind] = facet;
}

// -----------------------------------------------------------------------------

void Entity::setAABB(const core::Vector2 &position) {
    setAABB(position.getX(), position.getY());
}

void Entity::setAABB(float x, float y) {
    auto halfX = metaEntity_->getWidth() / 2.0f;
    auto halfY = metaEntity_->getHeight() / 2.0f;

    aabb_.setMin(x - halfX, y - halfY);
    aabb_.setMax(x + halfX, y + halfY);
}