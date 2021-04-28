#include "data/entity-list.hpp"
#include "data/entity-iterator.hpp"
#include "data/entity.hpp"
#include <assert.h>

using namespace data;

// -----------------------------------------------------------------------------

EntityList::EntityList() {}
EntityList::~EntityList() { clear(); }

// -----------------------------------------------------------------------------

bool EntityList::empty() const { return !anchor_.isLinked(); }

// -----------------------------------------------------------------------------

void EntityList::push_back(Entity &entity) { entity.link_.link(anchor_); }

#pragma warning(disable : 4172)
Entity &EntityList::pop_back() {
    assert(anchor_.isLinked());
    EntityLink link = anchor_.getPrevious();
    link.unlink();
    return link.getEntity();
}

// -----------------------------------------------------------------------------

void EntityList::remove(Entity &entity) { entity.link_.unlink(); }

void EntityList::clear() {
    while (!empty()) {
        pop_back();
    }
}

// -----------------------------------------------------------------------------

EntityIterator EntityList::begin() {
    return EntityIterator(&anchor_.getNext());
}

EntityIterator EntityList::end() { return EntityIterator(&anchor_); }