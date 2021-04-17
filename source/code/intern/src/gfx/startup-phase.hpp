#pragma once

#include "core/event-listener.hpp"
#include "core/singleton.hpp"

// -----------------------------------------------------------------------------

namespace gfx {

class StartupPhase : public core::Singleton<StartupPhase>,
                     public core::EventListener {
  public:
    void onEnter();
    void onLeave();

    void render();

    void onEvent(core::Event &event);

  private:
    template <class T> friend class core::Singleton;
    StartupPhase();
    ~StartupPhase();
};

} // namespace gfx