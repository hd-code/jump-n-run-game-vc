#pragma once

// -----------------------------------------------------------------------------

namespace data {

class Entity;
class EntityLink;

class EntityIterator {
public:
    EntityIterator();
    EntityIterator(const EntityIterator &other);

    Entity &operator*();
    Entity *operator->();

private:
    friend class EntityLink;
    EntityIterator(EntityLink *link);

    EntityLink *currentLink;
};

} // namespace data