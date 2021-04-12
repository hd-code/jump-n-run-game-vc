#pragma once

// -----------------------------------------------------------------------------

namespace data {

class Event;

class EventListener {
public:
    virtual void onEvent(Event &event) = 0;
};

} // namespace data