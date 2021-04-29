#pragma once

#include "SFML/System.hpp"
#include "core/singleton.hpp"
#include "game/base-phase.hpp"

// -----------------------------------------------------------------------------

namespace game {

class ShutdownPhase : public core::Singleton<ShutdownPhase>, public BasePhase {
  public:
    void onEnter(sf::RenderWindow &window);
    void onLeave();
    PhaseKind::Enum onRun();

  private:
    template <class T> friend class core::Singleton;
    ShutdownPhase();
    ~ShutdownPhase();

    sf::Clock clock_;
    bool shutdownFired_;
};

} // namespace game