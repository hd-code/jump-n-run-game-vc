#pragma once

#include "SFML/Graphics.hpp"
#include "core/singleton.hpp"
#include "game/base-phase.hpp"

namespace game {

class App : public core::Singleton<App> {
  public:
    void start(unsigned int width, unsigned int height);
    void exit();
    void run();

  private:
    template <class T> friend class core::Singleton;
    App();
    ~App();

    void handleEventQueue();
    void onRun();
    void onTransition(PhaseKind::Enum nextPhase);

    BasePhase *getPhase() const;
    PhaseKind::Enum phaseIndex_;
    BasePhase *phases_[PhaseKind::Length];

    sf::RenderWindow window_;
};

} // namespace game