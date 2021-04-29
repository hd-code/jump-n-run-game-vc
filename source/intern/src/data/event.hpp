#pragma once

#include "core/user-input.hpp"

// -----------------------------------------------------------------------------

namespace tinyxml2 {
class XMLElement;
}

namespace data {

class Entity;

enum class EventKind {
    UserInput,

    MetaEntities_clear,
    MetaEntity_load,

    Entities_clear,
    Entity_load,
    Entity_move,
};

union EventData {
    void *other;
    core::UserInput key;
    tinyxml2::XMLElement *xmlElement;
    Entity *entity;
};

class Event {
  public:
    Event();
    Event(const Event &other);
    ~Event();

    EventKind getKind() const;
    EventData getData() const;

  private:
    friend class EventSystem;
    Event(EventKind kind);
    Event(EventKind kind, EventData data);

    EventKind kind_;
    EventData data_;
};

} // namespace data