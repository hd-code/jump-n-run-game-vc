#pragma once

#include "SFML/System.hpp"
#include "core/singleton.hpp"
#include "game/base-phase.hpp"

// -----------------------------------------------------------------------------

namespace game {

class LoadMapPhase : public core::Singleton<LoadMapPhase>, public BasePhase {
  public:
    void onEnter(sf::RenderWindow &window);
    void onLeave();
    PhaseKind::Enum onRun();

  private:
    template <class T> friend class core::Singleton;
    LoadMapPhase();
    ~LoadMapPhase();

    sf::Clock clock_;
};

} // namespace game