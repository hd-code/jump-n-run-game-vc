#pragma once

#include "core/singleton.hpp"
#include "game/base-phase.hpp"

// -----------------------------------------------------------------------------

namespace game {

class MainMenuPhase : public core::Singleton<MainMenuPhase>, public BasePhase {
  public:
    void onEnter();
    void onLeave();
    PhaseKind::Enum onRun();

  private:
    template <class T> friend class core::Singleton;
    MainMenuPhase();
    ~MainMenuPhase();
};

} // namespace game