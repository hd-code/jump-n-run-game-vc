#pragma once

#include "SFML/System.hpp"
#include "core/singleton.hpp"
#include "game/base-phase.hpp"

// -----------------------------------------------------------------------------

namespace game {

class UnloadMapPhase : public core::Singleton<UnloadMapPhase>,
                       public BasePhase {
  public:
    void onEnter(sf::RenderWindow &window);
    void onLeave();
    PhaseKind::Enum onRun();

  private:
    template <class T> friend class core::Singleton;
    UnloadMapPhase();
    ~UnloadMapPhase();

    sf::Clock clock_;
};

} // namespace game