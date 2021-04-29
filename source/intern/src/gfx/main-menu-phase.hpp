#pragma once

#include "SFML/Graphics.hpp"
#include "core/singleton.hpp"
#include "gui/main-menu-phase.hpp"

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

    sf::RenderWindow *window_;

    sf::Texture textures_[gui::SelectedLabel::Length];
    sf::Sprite screens_[gui::SelectedLabel::Length];
};

} // namespace gfx