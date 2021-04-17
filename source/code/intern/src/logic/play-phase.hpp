#pragma once

#include "core/event-listener.hpp"
#include "core/singleton.hpp"

// -----------------------------------------------------------------------------

namespace logic {

class PlayPhase : public core::Singleton<PlayPhase>,
                  public core::EventListener {
  public:
    void onEnter();
    void onLeave();
    void onRun();

    void onEvent(core::Event &event);

  private:
    template <class T> friend class core::Singleton;
    PlayPhase();
    ~PlayPhase();
};

} // namespace logic