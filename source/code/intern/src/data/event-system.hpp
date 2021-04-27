#pragma once

#include "core/singleton.hpp"
#include "data/event.hpp"
#include <list>
#include <vector>

// -----------------------------------------------------------------------------

namespace data {

class EventListener;

class EventSystem : public core::Singleton<EventSystem> {
  public:
    void addEvent(EventKind kind);
    void addEvent(EventKind kind, EventData data);

    /// Fires all events that were added before by the `addEvent` method.
    void fireEvents();

    void fireEvent(EventKind kind);
    void fireEvent(EventKind kind, EventData data);

    void addEventListener(EventListener &eventListener);
    void removeEventListener(EventListener &eventListener);

  private:
    template <class T> friend class core::Singleton;
    EventSystem();
    ~EventSystem();

    void fireEvent(const Event &event);

    std::vector<Event> events_;
    std::list<EventListener *> eventListeners_;
};

} // namespace data