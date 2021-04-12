#include "data/entity-link.hpp"

#include "data/entity.hpp"

#include <stdlib.h>

using namespace data;

// -----------------------------------------------------------------------------

EntityLink::EntityLink() {
    previous = this;
    next = this;
}

EntityLink::~EntityLink() {
    if (isLinked()) {
        unlink();
    }
}

// -----------------------------------------------------------------------------

Entity &EntityLink::getEntity() {
    return *reinterpret_cast<Entity *>(
        reinterpret_cast<ptrdiff_t>(this) -
        (reinterpret_cast<ptrdiff_t>(
             &(static_cast<Entity *>(nullptr)->*(&Entity::link))) -
         reinterpret_cast<ptrdiff_t>(static_cast<void *>(nullptr))));
}

const Entity &EntityLink::getEntity() const {
    return *reinterpret_cast<Entity *>(
        reinterpret_cast<ptrdiff_t>(this) -
        (reinterpret_cast<ptrdiff_t>(
             &(static_cast<Entity *>(nullptr)->*(&Entity::link))) -
         reinterpret_cast<ptrdiff_t>(static_cast<void *>(nullptr))));
}

// -----------------------------------------------------------------------------

void EntityLink::link(EntityLink &anchor) {
    if (isLinked()) {
        unlink();
    }

    previous = &anchor;
    next = anchor.next;

    previous->next = this;
    next->previous = this;
}

void EntityLink::unlink() {
    previous->next = next;
    next->previous = previous;

    previous = this;
    next = this;
}

// -----------------------------------------------------------------------------

bool EntityLink::isLinked() const { return previous != this && next != this; }

// -----------------------------------------------------------------------------

EntityLink &EntityLink::getPrevious() { return *previous; }

EntityLink &EntityLink::getNext() { return *next; }
