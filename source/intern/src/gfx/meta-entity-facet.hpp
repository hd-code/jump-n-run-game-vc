#pragma once

#include "SFML/Graphics.hpp"

namespace gfx {

class MetaEntityFacet {
  public:
    MetaEntityFacet();
    ~MetaEntityFacet();

    sf::Texture &getTexture();
    bool setTexture(const std::string &filename);

  private:
    sf::Texture texture_;
};

} // namespace gfx