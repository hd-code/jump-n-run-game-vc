#include "data/event-system.hpp"
#include "data/event-listener.hpp"

using namespace data;

// -----------------------------------------------------------------------------

EventSystem::EventSystem() : events_(), eventListeners_() {}

EventSystem::~EventSystem() {
    events_.clear();
    eventListeners_.clear();
}

// -----------------------------------------------------------------------------

void EventSystem::addEvent(EventKind kind) {
    Event event(kind);
    events_.push_back(event);
}

void EventSystem::addEvent(EventKind kind, EventData data) {
    Event event(kind, data);
    events_.push_back(event);
}

// -----------------------------------------------------------------------------

void EventSystem::fireEvents() {
    for (auto i = 0, size = (int)events_.size(); i < size; ++i) {
        fireEvent(events_[i]);
    }
    events_.clear();
}

// -----------------------------------------------------------------------------

void EventSystem::fireEvent(EventKind kind) {
    Event event(kind);
    fireEvent(event);
}

void EventSystem::fireEvent(EventKind kind, EventData data) {
    Event event(kind, data);
    fireEvent(event);
}

void EventSystem::fireEvent(const Event &event) {
    auto iterator = eventListeners_.begin();
    auto end = eventListeners_.end();
    while (iterator != end) {
        auto eventlistener = *iterator;
        eventlistener->onEvent(event);
        ++iterator;
    }
}

// -----------------------------------------------------------------------------

void EventSystem::addEventListener(EventListener &eventListener) {
    eventListeners_.push_back(&eventListener);
}

void EventSystem::removeEventListener(EventListener &eventListener) {
    eventListeners_.remove(&eventListener);
}