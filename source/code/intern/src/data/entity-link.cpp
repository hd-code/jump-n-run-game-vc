#include "data/entity-link.hpp"
#include "data/entity.hpp"
#include <stdlib.h>

using namespace data;

// -----------------------------------------------------------------------------

EntityLink::EntityLink() : previous_(this), next_(this) {}

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
             &(static_cast<Entity *>(nullptr)->*(&Entity::link_))) -
         reinterpret_cast<ptrdiff_t>(static_cast<void *>(nullptr))));
}

const Entity &EntityLink::getEntity() const {
    return *reinterpret_cast<Entity *>(
        reinterpret_cast<ptrdiff_t>(this) -
        (reinterpret_cast<ptrdiff_t>(
             &(static_cast<Entity *>(nullptr)->*(&Entity::link_))) -
         reinterpret_cast<ptrdiff_t>(static_cast<void *>(nullptr))));
}

// -----------------------------------------------------------------------------

EntityLink &EntityLink::getPrevious() { return *previous_; }
const EntityLink &EntityLink::getPrevious() const { return *previous_; }

// -----------------------------------------------------------------------------

EntityLink &EntityLink::getNext() { return *next_; }
const EntityLink &EntityLink::getNext() const { return *next_; }

// -----------------------------------------------------------------------------

bool EntityLink::isLinked() const { return previous_ != this && next_ != this; }

// -----------------------------------------------------------------------------

void EntityLink::link(EntityLink &anchor) {
    if (isLinked()) {
        unlink();
    }

    previous_ = anchor.previous_;
    next_ = &anchor;

    previous_->next_ = this;
    next_->previous_ = this;
}

void EntityLink::unlink() {
    previous_->next_ = next_;
    next_->previous_ = previous_;

    previous_ = this;
    next_ = this;
}