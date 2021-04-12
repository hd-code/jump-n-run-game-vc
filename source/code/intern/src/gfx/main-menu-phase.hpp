#pragma once

/* #include "core/singleton.hpp"

#include "SFML/Graphics.hpp"

// -----------------------------------------------------------------------------

namespace gfx {

class MainMenuPhase : public core::Singleton<MainMenuPhase> {
public:
    void onEnter(sf::RenderWindow &window);
    void onLeave();

    void render();

private:
    template <class T> friend class core::Singleton;
    MainMenuPhase();
    ~MainMenuPhase();

    sf::RenderWindow *window;
    sf::Text labels[2];
};

} // namespace gfx */