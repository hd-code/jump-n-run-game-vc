#pragma once

// -----------------------------------------------------------------------------

namespace data {

enum class EventType {
    Entity,
    Window,
};

class Event {
public:
    EventType getType() const;
};

} // namespace data