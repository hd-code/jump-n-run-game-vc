#pragma once

#include "core/singleton.hpp"
#include <list>

// -----------------------------------------------------------------------------

namespace core {

class Event;
class EventListener;

class EventSystem : public core::Singleton<EventSystem> {
  public:
    void addEvent(Event &event);
    void fireEvent(Event &event);
    void fireEvents();

    void addEventListener(EventListener &eventListener);
    void removeEventListener(EventListener &eventListener);

  private:
    template <class T> friend class core::Singleton;
    EventSystem();
    ~EventSystem();

    std::list<Event *> events_;
    std::list<EventListener *> eventListeners_;
};

} // namespace core