#pragma once

// -----------------------------------------------------------------------------

namespace core {

class Event;

class EventListener {
  public:
    virtual void onEvent(Event &event) = 0;
};

} // namespace core