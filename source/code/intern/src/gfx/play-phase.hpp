#pragma once

#include "SFML/Graphics.hpp"
#include "core/singleton.hpp"
#include "data/event-listener.hpp"

// -----------------------------------------------------------------------------

namespace gfx {

class PlayPhase : public core::Singleton<PlayPhase>,
                  public data::EventListener {
  public:
    void onEnter(sf::RenderWindow &window);
    void onLeave();

    void render();

    void onEvent(const data::Event &event);

  private:
    template <class T> friend class core::Singleton;
    PlayPhase();
    ~PlayPhase();

    sf::RenderWindow *window_;
    sf::View view_;
};

} // namespace gfx