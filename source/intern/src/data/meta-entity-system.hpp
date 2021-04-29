#pragma once

#include "core/id-manager.hpp"
#include "core/item-manager.hpp"
#include "core/singleton.hpp"
#include "data/meta-entity.hpp"

// -----------------------------------------------------------------------------

namespace data {

class MetaEntitySystem : public core::Singleton<MetaEntitySystem> {
  public:
    MetaEntity &create(const std::string &name);

    MetaEntity &get(const std::string &name);
    MetaEntity &get(MetaEntity::Id id);

    void clear();

  private:
    template <class T> friend class core::Singleton;
    MetaEntitySystem();
    ~MetaEntitySystem();

    core::IdManager idManager_;
    core::ItemManager<MetaEntity> itemManager_;
};

} // namespace data