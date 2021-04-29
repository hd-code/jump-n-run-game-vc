#pragma once

#include "SFML/Graphics.hpp"
#include "core/singleton.hpp"
#include "data/event-listener.hpp"

// -----------------------------------------------------------------------------

namespace tinyxml2 {
class XMLElement;
}

namespace gfx {

class LoadMapPhase : public core::Singleton<LoadMapPhase>,
                     public data::EventListener {
  public:
    void onEnter(sf::RenderWindow &window);
    void onLeave();

    void render();

    void onEvent(const data::Event &event);

  private:
    template <class T> friend class core::Singleton;
    LoadMapPhase();
    ~LoadMapPhase();

    void loadEntity(tinyxml2::XMLElement *xml);

    sf::RenderWindow *window_;

    sf::Texture screenTexture_;
    sf::Sprite screen_;
};

} // namespace gfx