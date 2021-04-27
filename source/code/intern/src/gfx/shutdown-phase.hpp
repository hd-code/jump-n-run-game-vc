#pragma once

#include "SFML/Graphics.hpp"
#include "core/singleton.hpp"
#include "data/event-listener.hpp"

// -----------------------------------------------------------------------------

namespace gfx {

class ShutdownPhase : public core::Singleton<ShutdownPhase>,
                      public data::EventListener {
  public:
    void onEnter(sf::RenderWindow &window);
    void onLeave();

    void render();

    void onEvent(const data::Event &event);

  private:
    template <class T> friend class core::Singleton;
    ShutdownPhase();
    ~ShutdownPhase();

    sf::RenderWindow *window_;

    sf::Texture screenTexture_;
    sf::Sprite screen_;
};

} // namespace gfx