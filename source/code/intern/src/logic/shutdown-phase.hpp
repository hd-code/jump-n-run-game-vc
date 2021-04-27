#pragma once

#include "core/singleton.hpp"
#include "data/event-listener.hpp"

// -----------------------------------------------------------------------------

namespace logic {

class ShutdownPhase : public core::Singleton<ShutdownPhase>,
                      public data::EventListener {
  public:
    void onEnter();
    void onLeave();

    void onEvent(const data::Event &event);

  private:
    template <class T> friend class core::Singleton;
    ShutdownPhase();
    ~ShutdownPhase();
};

} // namespace logic