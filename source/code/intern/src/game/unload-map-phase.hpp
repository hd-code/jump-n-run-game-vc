#pragma once

#include "core/singleton.hpp"
#include "game/base-phase.hpp"

// -----------------------------------------------------------------------------

namespace game {

class UnloadMapPhase : public core::Singleton<UnloadMapPhase>,
                       public BasePhase {
  public:
    void onEnter();
    void onLeave();
    int onRun();

  private:
    template <class T> friend class core::Singleton;
    UnloadMapPhase();
    ~UnloadMapPhase();
};

} // namespace game