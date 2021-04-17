#pragma once

// -----------------------------------------------------------------------------

namespace core {

enum class EventKind {
    Entity,
    Window,
};

class Event {
  public:
    virtual EventKind getType() const = 0;
};

} // namespace core