#pragma once

#include "SFML/System.hpp"
#include "core/singleton.hpp"
#include "game/base-phase.hpp"

// -----------------------------------------------------------------------------

namespace game {

class StartupPhase : public core::Singleton<StartupPhase>, public BasePhase {
  public:
    void onEnter(sf::RenderWindow &window);
    void onLeave();
    PhaseKind::Enum onRun();

  private:
    template <class T> friend class core::Singleton;
    StartupPhase();
    ~StartupPhase();

    sf::Clock clock_;
};

} // namespace game