#pragma once

#include "SFML/System.hpp"
#include "core/singleton.hpp"
#include "game/base-phase.hpp"

// -----------------------------------------------------------------------------

namespace game {

class PlayPhase : public core::Singleton<PlayPhase>, public BasePhase {
  public:
    void onEnter(sf::RenderWindow &window);
    void onLeave();
    PhaseKind::Enum onRun();

  private:
    static constexpr int timeBetweenTurns_ = 200;

    template <class T> friend class core::Singleton;
    PlayPhase();
    ~PlayPhase();

    sf::Clock clock_;
};

} // namespace game