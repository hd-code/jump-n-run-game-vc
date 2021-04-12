#pragma once

#include "core/singleton.hpp"
#include "game/base-phase.hpp"

// -----------------------------------------------------------------------------

namespace game {

class LoadMapPhase : public core::Singleton<LoadMapPhase>, public BasePhase {
  public:
    void onEnter();
    void onLeave();
    int onRun();

  private:
    template <class T> friend class core::Singleton;
    LoadMapPhase();
    ~LoadMapPhase();
};

} // namespace game