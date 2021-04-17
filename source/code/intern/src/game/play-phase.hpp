#pragma once

#include "core/singleton.hpp"
#include "game/base-phase.hpp"

// -----------------------------------------------------------------------------

namespace game {

class PlayPhase : public core::Singleton<PlayPhase>, public BasePhase {
  public:
    void onEnter();
    void onLeave();
    PhaseKind::Enum onRun();

  private:
    template <class T> friend class core::Singleton;
    PlayPhase();
    ~PlayPhase();
};

} // namespace game