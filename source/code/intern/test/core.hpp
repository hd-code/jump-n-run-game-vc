#pragma once

#include "core/item-system.hpp"
#include <iostream>
#include <string>

namespace testcore {

class MetaEntity {
  public:
    MetaEntity() {}
    ~MetaEntity() {}
};

class MetaEntitySystem : public core::ItemSystem<MetaEntity> {
  private:
    MetaEntitySystem() {}
    ~MetaEntitySystem() {}
};

class Entity {
  public:
    Entity() : metaEntity_(nullptr) {}
    ~Entity() {}

    MetaEntity *&getMetaEntity() { return metaEntity_; }
    void setMetaEntity(MetaEntity &metaEntity) { metaEntity_ = &metaEntity; }

  private:
    MetaEntity *metaEntity_;
};

class EntitySystem : public core::ItemSystem<Entity> {
  private:
    EntitySystem() {}
    ~EntitySystem() {}
};

void main() {
    std::cout << "-- Testing ItemSystem" << std::endl;

    auto &metaA = MetaEntitySystem::getInstance().create("A");
    std::cout << "create MetaEntity, addr: " << &metaA << std::endl;

    auto &metaB = MetaEntitySystem::getInstance().create("B");
    std::cout << "create MetaEntity, addr: " << &metaB << std::endl;

    auto &entityA = EntitySystem::getInstance().create("A");
    std::cout << "create Entity, addr: " << &entityA << std::endl;

    auto &entityB = EntitySystem::getInstance().create("B");
    std::cout << "create Entity, addr: " << &entityB << std::endl;

    auto &entityC = EntitySystem::getInstance().create("C");
    std::cout << "create Entity, addr: " << &entityC << std::endl;

    entityA.setMetaEntity(metaA);
    entityB.setMetaEntity(metaB);
    entityC.setMetaEntity(metaA);

    EntitySystem::getInstance().clear();
    MetaEntitySystem::getInstance().clear();

    std::cout << "-- End Testing ItemSystem" << std::endl << std::endl;
}

} // namespace testcore