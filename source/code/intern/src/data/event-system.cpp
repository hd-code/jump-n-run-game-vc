#include "data/event-system.hpp"

#include "data/event-listener.hpp"
#include "data/event.hpp"

using namespace data;

// -----------------------------------------------------------------------------

EventSystem::EventSystem() {}
EventSystem::~EventSystem() {}

// -----------------------------------------------------------------------------

void EventSystem::addEvent(Event &event) { events.push_back(&event); }

void EventSystem::fireEvent(Event &event) {
    for (auto eventListener : eventListeners) {
        eventListener->onEvent(event);
    }
}

void EventSystem::fireEvents() {
    while (events.size() > 0) {
        Event event = **events.begin();
        fireEvent(event);
        events.pop_front();
    }
}

// -----------------------------------------------------------------------------

void EventSystem::addEventListener(EventListener &eventListener) {
    eventListeners.push_back(&eventListener);
}

void EventSystem::removeEventListener(EventListener &eventListener) {
    eventListeners.remove(&eventListener);
}