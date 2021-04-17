#pragma once

#include "core/event-listener.hpp"
#include "core/singleton.hpp"

// -----------------------------------------------------------------------------

namespace logic {

class StartupPhase : public core::Singleton<StartupPhase>,
                     public core::EventListener {
  public:
    void onEnter();
    void onLeave();
    void onRun();

    void onEvent(core::Event &event);

  private:
    template <class T> friend class core::Singleton;
    StartupPhase();
    ~StartupPhase();
};

} // namespace logic