#pragma once

namespace sf {
class RenderWindow;
}

namespace game {

struct PhaseKind {
    typedef enum {
        Exit = -1,
        Startup,
        MainMenu,
        LoadMap,
        Play,
        UnloadMap,
        Shutdown,
        Length,
    } Enum;
};

class BasePhase {
  public:
    virtual void onEnter(sf::RenderWindow &window) = 0;
    virtual void onLeave() = 0;
    virtual PhaseKind::Enum onRun() = 0;
};

} // namespace game