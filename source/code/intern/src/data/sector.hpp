#pragma once

#include "data/entity-folder.hpp"
#include "data/entity-kind.hpp"

// -----------------------------------------------------------------------------

namespace core {
class AABB;
}

namespace data {

class Sector {
  public:
    static constexpr float size = 8.0f;

    Sector();
    ~Sector();

    void addEntity(Entity &entity);
    void removeEntity(Entity &entity);

    // When an empty iterator is returned, there is no matching entity in this
    // sector.
    EntityIterator searchSector(const core::AABB &aabb);
    EntityIterator searchSector(const core::AABB &aabb, EntityKind::Enum kind);
    EntityIterator searchSector(EntityIterator current, const core::AABB &aabb);
    EntityIterator searchSector(EntityIterator current, const core::AABB &aabb,
                                EntityKind::Enum kind);

  private:
    EntityIterator searchFolder(EntityIterator current, const core::AABB &aabb);
    EntityIterator searchNextFolders(EntityIterator current,
                                     const core::AABB &aabb);

    EntityFolder &getFolder(const EntityKind::Enum kind);
    EntityFolder &getFolder(int kind);

    EntityFolder folders_[EntityKind::Length];
};

} // namespace data