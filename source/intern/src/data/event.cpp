#include "data/event.hpp"

using namespace data;

// -----------------------------------------------------------------------------

Event::Event() {}
Event::Event(const Event &other) : kind_(other.kind_), data_(other.data_) {}

Event::Event(EventKind kind) : kind_(kind) { data_.other = nullptr; }
Event::Event(EventKind kind, EventData data) : kind_(kind), data_(data) {}

Event::~Event() {}

// -----------------------------------------------------------------------------

EventKind Event::getKind() const { return kind_; }
EventData Event::getData() const { return data_; }