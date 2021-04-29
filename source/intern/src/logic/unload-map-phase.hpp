#pragma once

#include "core/singleton.hpp"
#include "data/event-listener.hpp"

// -----------------------------------------------------------------------------

namespace logic {

class UnloadMapPhase : public core::Singleton<UnloadMapPhase>,
                       public data::EventListener {
  public:
    void onEnter();
    void onLeave();

    void onEvent(const data::Event &event);

  private:
    template <class T> friend class core::Singleton;
    UnloadMapPhase();
    ~UnloadMapPhase();
};

} // namespace logic