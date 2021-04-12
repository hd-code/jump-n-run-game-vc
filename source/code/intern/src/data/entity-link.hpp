#pragma once

namespace data {

class Entity;

class EntityLink {
  public:
    EntityLink();
    ~EntityLink();

    Entity &getEntity();
    const Entity &getEntity() const;

    // The link will be appended to the anchor
    void link(EntityLink &anchor);
    void unlink();

    bool isLinked() const;

    EntityLink &getPrevious();
    EntityLink &getNext();

  private:
    EntityLink *previous;
    EntityLink *next;
};

} // namespace data