#pragma once

#include "core/singleton.hpp"
#include "data/event-listener.hpp"

// -----------------------------------------------------------------------------

namespace tinyxml2 {
class XMLElement;
}

namespace logic {

class LoadMapPhase : public core::Singleton<LoadMapPhase>,
                     public data::EventListener {
  public:
    void onEnter();
    void onLeave();

    void onEvent(const data::Event &event);

  private:
    template <class T> friend class core::Singleton;
    LoadMapPhase();
    ~LoadMapPhase();

    void loadEntity(tinyxml2::XMLElement *xml);
};

} // namespace logic