#pragma once

#include "core/singleton.hpp"
#include "game/base-phase.hpp"

// -----------------------------------------------------------------------------

namespace game {

class StartupPhase : public core::Singleton<StartupPhase>, public BasePhase {
  public:
    void onEnter();
    void onLeave();
    int onRun();

  private:
    template <class T> friend class core::Singleton;
    StartupPhase();
    ~StartupPhase();
};

} // namespace game