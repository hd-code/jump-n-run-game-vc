#pragma once

#include "core/singleton.hpp"
#include "core/vector2.hpp"
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

    core::Vector2 &getCameraPosition();
    const core::Vector2 &getCameraPosition() const;

  private:
    template <class T> friend class core::Singleton;
    PlayPhase();
    ~PlayPhase();

    typedef enum { None, Up, Down, Left, Right } Direction;
    void moveCamera();

    const float cameraMoveWidth_ = 0.2f;
    core::Vector2 cameraPosition_;
    Direction nextCameraMove_;
    bool leaveLevel_;
};

} // namespace logic