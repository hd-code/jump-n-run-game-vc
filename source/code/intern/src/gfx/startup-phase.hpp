#pragma once

#include "SFML/Graphics.hpp"
#include "core/singleton.hpp"
#include "data/event-listener.hpp"

// -----------------------------------------------------------------------------

namespace tinyxml2 {
class XMLElement;
}

namespace gfx {

class StartupPhase : public core::Singleton<StartupPhase>,
                     public data::EventListener {
  public:
    void onEnter(sf::RenderWindow &window);
    void onLeave();

    void render();

    void onEvent(const data::Event &event);

  private:
    template <class T> friend class core::Singleton;
    StartupPhase();
    ~StartupPhase();

    void loadMetaEntity(tinyxml2::XMLElement *xml);

    sf::RenderWindow *window_;

    sf::Texture screenTexture_;
    sf::Sprite screen_;
};

} // namespace gfx