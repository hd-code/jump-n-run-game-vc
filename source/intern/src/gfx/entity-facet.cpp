#include "gfx/entity-facet.hpp"
#include "core/vector2.hpp"

using namespace gfx;

// -----------------------------------------------------------------------------

EntityFacet::EntityFacet() {}

EntityFacet::~EntityFacet() {}

void EntityFacet::init(float width, float height, const core::Vector2 &position,
                       sf::Texture &texture) {
    sprite_.setSize(sf::Vector2f(width, height));
    sprite_.setPosition(position.getX(), position.getY());
    sprite_.setTexture(&texture);
}

// -----------------------------------------------------------------------------

sf::RectangleShape &EntityFacet::getSprite() { return sprite_; }

// -----------------------------------------------------------------------------

void EntityFacet::setPosition(float x, float y) { sprite_.setPosition(x, y); }