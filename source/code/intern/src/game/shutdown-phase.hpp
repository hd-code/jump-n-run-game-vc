#pragma once

#include "core/singleton.hpp"
#include "game/base-phase.hpp"

// -----------------------------------------------------------------------------

namespace game {

class ShutdownPhase : public core::Singleton<ShutdownPhase>, public BasePhase {
  public:
    void onEnter();
    void onLeave();
    int onRun();

  private:
    template <class T> friend class core::Singleton;
    ShutdownPhase();
    ~ShutdownPhase();
};

} // namespace game