#include "gfx/meta-entity-facet.hpp"
#include "core/config.hpp"

using namespace gfx;

// -----------------------------------------------------------------------------

MetaEntityFacet::MetaEntityFacet() : texture_() {}

MetaEntityFacet::~MetaEntityFacet() {}

// -----------------------------------------------------------------------------

sf::Texture &MetaEntityFacet::getTexture() { return texture_; }

// -----------------------------------------------------------------------------

bool MetaEntityFacet::setTexture(const std::string &filename) {
    std::string filepath = core::Config::textureDir + filename;
    return texture_.loadFromFile(filepath);
}