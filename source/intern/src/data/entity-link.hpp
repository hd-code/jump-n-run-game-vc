#pragma once

namespace data {

class Entity;

class EntityLink {
  public:
    EntityLink();
    ~EntityLink();

    Entity &getEntity();
    const Entity &getEntity() const;

    EntityLink &getPrevious();
    const EntityLink &getPrevious() const;

    EntityLink &getNext();
    const EntityLink &getNext() const;

    bool isLinked() const;

    void link(EntityLink &anchor);
    void unlink();

  private:
    EntityLink *previous_;
    EntityLink *next_;
};

} // namespace data