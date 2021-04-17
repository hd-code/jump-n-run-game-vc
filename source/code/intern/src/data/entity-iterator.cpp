#include "data/entity-iterator.hpp"
#include "data/entity-link.hpp"
#include <assert.h>

using namespace data;

// -----------------------------------------------------------------------------

EntityIterator::EntityIterator() : link_(nullptr) {}

EntityIterator::EntityIterator(const EntityIterator &other)
    : link_(other.link_) {}

EntityIterator::EntityIterator(EntityLink *link) : link_(link) {}

// -----------------------------------------------------------------------------

EntityIterator &EntityIterator::operator++() {
    assert(link_ != nullptr);
    link_ = &link_->getNext();
    return *this;
}

EntityIterator EntityIterator::operator++(int) {
    auto previous = EntityIterator(link_);
    ++(*this);
    return previous;
}

// -----------------------------------------------------------------------------

Entity &EntityIterator::operator*() { return link_->getEntity(); }

Entity *EntityIterator::operator->() {
    assert(link_ != nullptr);
    return &link_->getEntity();
}

// -----------------------------------------------------------------------------

bool EntityIterator::operator==(const EntityIterator &other) {
    return link_ == other.link_;
}

bool EntityIterator::operator!=(const EntityIterator &other) {
    return link_ != other.link_;
}