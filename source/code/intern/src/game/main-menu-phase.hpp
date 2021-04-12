#pragma once

#include "SFML/Graphics.hpp"
#include "core/singleton.hpp"
#include "game/base-phase.hpp"

// -----------------------------------------------------------------------------

namespace game {

class MainMenuPhase : public core::Singleton<MainMenuPhase>, public BasePhase {
  public:
    void onEnter();
    void onLeave();
    int onRun();

    // TODO: use better structure
    void setWindow(sf::RenderWindow &window) { this->window = &window; }

  private:
    template <class T> friend class core::Singleton;
    MainMenuPhase();
    ~MainMenuPhase();

    sf::RenderWindow *window;
};

} // namespace game