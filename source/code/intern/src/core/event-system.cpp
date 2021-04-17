#include "core/event-system.hpp"
#include "core/event-listener.hpp"
#include "core/event.hpp"

using namespace core;

// -----------------------------------------------------------------------------

EventSystem::EventSystem() {}
EventSystem::~EventSystem() {}

// -----------------------------------------------------------------------------

void EventSystem::addEvent(Event &event) { events_.push_back(&event); }

void EventSystem::fireEvent(Event &event) {
    for (auto eventListener : eventListeners_) {
        eventListener->onEvent(event);
    }
}

void EventSystem::fireEvents() {
    while (events_.size() > 0) {
        Event *event = events_.front();
        fireEvent(*event);
        events_.pop_front();
        // delete event?
    }
}

// -----------------------------------------------------------------------------

void EventSystem::addEventListener(EventListener &eventListener) {
    eventListeners_.push_back(&eventListener);
}

void EventSystem::removeEventListener(EventListener &eventListener) {
    eventListeners_.remove(&eventListener);
}