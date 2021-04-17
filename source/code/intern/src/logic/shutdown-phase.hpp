#pragma once

#include "core/event-listener.hpp"
#include "core/singleton.hpp"

// -----------------------------------------------------------------------------

namespace logic {

class ShutdownPhase : public core::Singleton<ShutdownPhase>,
                      public core::EventListener {
  public:
    void onEnter();
    void onLeave();
    void onRun();

    void onEvent(core::Event &event);

  private:
    template <class T> friend class core::Singleton;
    ShutdownPhase();
    ~ShutdownPhase();
};

} // namespace logic