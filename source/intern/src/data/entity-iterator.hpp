#pragma once

// -----------------------------------------------------------------------------

namespace data {

class Entity;
class EntityLink;

class EntityIterator {
  public:
    /// Creates an empty entity iterator
    EntityIterator();
    EntityIterator(const EntityIterator &other);

    EntityIterator &operator++();
    EntityIterator operator++(int);

    Entity &operator*();
    Entity *operator->();

    bool operator==(const EntityIterator &other);
    bool operator!=(const EntityIterator &other);

  private:
    friend class EntityList;
    EntityIterator(EntityLink *link);

    EntityLink *link_;
};

} // namespace data