#pragma once

// -----------------------------------------------------------------------------

namespace data {

class Event;

class EventListener {
  public:
    virtual void onEvent(const Event &event) = 0;
};

} // namespace data