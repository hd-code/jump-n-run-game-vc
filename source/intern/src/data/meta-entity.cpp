#include "data/meta-entity.hpp"

using namespace data;

// -----------------------------------------------------------------------------

MetaEntity::MetaEntity()
    : kind_(EntityKind::Other), height_(0.0f), width_(0.0f) {
    for (auto i = 0; i < MetaEntityFacetKind::Length; ++i) {
        facets_[i] = nullptr;
    }
}

MetaEntity::~MetaEntity() {}

void MetaEntity::setId(Id id) { id_ = id; }

void MetaEntity::init(EntityKind::Enum kind, float height, float width) {
    kind_ = kind;
    height_ = height;
    width_ = width;
}

// -----------------------------------------------------------------------------

MetaEntity::Id MetaEntity::getId() const { return id_; }

EntityKind::Enum MetaEntity::getKind() const { return kind_; }

// -----------------------------------------------------------------------------

float MetaEntity::getHeight() const { return height_; }

float MetaEntity::getWidth() const { return width_; }

// -----------------------------------------------------------------------------

void *MetaEntity::getFacet(MetaEntityFacetKind::Enum kind) {
    return facets_[kind];
}

void MetaEntity::registerFacet(MetaEntityFacetKind::Enum kind, void *facet) {
    facets_[kind] = facet;
}