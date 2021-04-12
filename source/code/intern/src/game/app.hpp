#pragma once

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
    void onTransition(int nextPhase);

    BasePhase *getCurrentPhase();
    int currentPhaseIndex;
    BasePhase *phases[Phase::Length];
};

} // namespace game