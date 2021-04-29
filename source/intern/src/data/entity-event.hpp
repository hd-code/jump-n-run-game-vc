#pragma once

#include "core/event.hpp"
#include "tinyxml2/tinyxml2.h"

namespace data {

class MetaEntityEvent : public core::Event {
  public:
    MetaEntityEvent() : element_() {}
    ~MetaEntityEvent() {}

    core::EventKind getKind() const {
        return core::EventKind::MetaEntity_create;
    }

  private:
    tinyxml2::XMLElement *element_;
};

class EntityEvent : public core::Event {
  public:
    EntityEvent() : element_() {}
    ~EntityEvent() {}

    core::EventKind getKind() const { return core::EventKind::Entity_create; }

  private:
    tinyxml2::XMLElement *element_;
};

} // namespace data