#pragma once

namespace game {

struct Phase {
    enum {
        Startup,
        MainMenu,
        LoadMap,
        Play,
        UnloadMap,
        Shutdown,
        Length,
        Exit = -1,
    };
};

class BasePhase {
  public:
    virtual void onEnter() = 0;
    virtual void onLeave() = 0;
    virtual int onRun() = 0;
};

} // namespace game