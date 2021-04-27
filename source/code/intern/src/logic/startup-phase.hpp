#pragma once

#include "core/singleton.hpp"
#include "data/event-listener.hpp"

// -----------------------------------------------------------------------------

namespace tinyxml2 {
class XMLElement;
}

namespace logic {

class StartupPhase : public core::Singleton<StartupPhase>,
                     public data::EventListener {
  public:
    void onEnter();
    void onLeave();

    void onEvent(const data::Event &event);

  private:
    template <class T> friend class core::Singleton;
    StartupPhase();
    ~StartupPhase();

    void loadMetaEntity(tinyxml2::XMLElement *xml);
};

} // namespace logic