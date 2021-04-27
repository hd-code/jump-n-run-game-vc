#pragma once

#include "SFML/Graphics.hpp"
#include "core/singleton.hpp"
#include "data/event-listener.hpp"

// -----------------------------------------------------------------------------

namespace gfx {

class UnloadMapPhase : public core::Singleton<UnloadMapPhase>,
                       public data::EventListener {
  public:
    void onEnter(sf::RenderWindow &window);
    void onLeave();

    void render();

    void onEvent(const data::Event &event);

  private:
    template <class T> friend class core::Singleton;
    UnloadMapPhase();
    ~UnloadMapPhase();

    sf::RenderWindow *window_;

    sf::Texture screenTexture_;
    sf::Sprite screen_;
};

} // namespace gfx