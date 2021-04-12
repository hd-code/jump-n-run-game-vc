#include "data/entity-list.hpp"

#include "data/entity.hpp"

using namespace data;

// -----------------------------------------------------------------------------

EntityList::EntityList() {}
EntityList::~EntityList() { clear(); }

// -----------------------------------------------------------------------------

bool EntityList::isEmpty() const { return !anchor.isLinked(); }

// -----------------------------------------------------------------------------

void EntityList::push(Entity &entity) { entity.link.link(anchor); }

Entity &EntityList::pop() {
    assert(anchor.isLinked());
    EntityLink link = anchor.getPrevious();
    link.unlink();
    return link.getEntity();
}

// -----------------------------------------------------------------------------

void EntityList::remove(Entity &entity) { entity.link.unlink(); }

void EntityList::clear() {
    while (!isEmpty()) {
        pop();
    }
}