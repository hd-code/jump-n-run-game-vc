#pragma once

#include "SFML/Graphics.hpp"

// -----------------------------------------------------------------------------

namespace core {
class Vector2;
}

namespace gfx {

class EntityFacet {
  public:
    EntityFacet();
    ~EntityFacet();

    sf::RectangleShape &getSprite();

    void setPosition(float x, float y);

  private:
    friend class LoadMapPhase;
    void init(float width, float height, const core::Vector2 &position,
              sf::Texture &texture);

    sf::RectangleShape sprite_;
};

} // namespace gfx