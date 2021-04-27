#pragma once

#include "core/singleton.hpp"
#include "data/event-listener.hpp"

// -----------------------------------------------------------------------------

namespace logic {

class PlayPhase : public core::Singleton<PlayPhase>,
                  public data::EventListener {
  public:
    void onEnter();
    void onLeave();
    /// Does a logic turn. Returns false, when the game should not continue.
    bool onRun();

    void onEvent(const data::Event &event);

  private:
    template <class T> friend class core::Singleton;
    PlayPhase();
    ~PlayPhase();

    bool leaveLevel_;
};

} // namespace logic