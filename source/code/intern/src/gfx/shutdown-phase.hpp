#pragma once

#include "core/event-listener.hpp"
#include "core/singleton.hpp"

// -----------------------------------------------------------------------------

namespace gfx {

class ShutdownPhase : public core::Singleton<ShutdownPhase>,
                      public core::EventListener {
  public:
    void onEnter();
    void onLeave();

    void onEvent(core::Event &event);

  private:
    template <class T> friend class core::Singleton;
    ShutdownPhase();
    ~ShutdownPhase();
};

} // namespace gfx