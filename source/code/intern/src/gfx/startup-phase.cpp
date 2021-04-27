#include "gfx/startup-phase.hpp"
#include "core/config.hpp"
#include "data/event-system.hpp"
#include "data/meta-entity-system.hpp"
#include "gfx/meta-entity-facet-system.hpp"
#include "tinyxml2/tinyxml2.h"
#include <assert.h>

using namespace gfx;

// -----------------------------------------------------------------------------

StartupPhase::StartupPhase() : window_(nullptr), screenTexture_(), screen_() {}

StartupPhase::~StartupPhase() {}

// -----------------------------------------------------------------------------

void StartupPhase::onEnter(sf::RenderWindow &window) {
    window_ = &window;
    data::EventSystem::getInstance().addEventListener(*this);

    std::string filepath = core::Config::screensDir + "startup.png";
    assert(screenTexture_.loadFromFile(filepath));
    screen_.setTexture(screenTexture_);
}

void StartupPhase::onLeave() {
    data::EventSystem::getInstance().removeEventListener(*this);
}

// -----------------------------------------------------------------------------

void StartupPhase::render() {
    window_->clear();
    window_->draw(screen_);
    window_->display();
}

// -----------------------------------------------------------------------------

void StartupPhase::onEvent(const data::Event &event) {
    switch (event.getKind()) {
    case data::EventKind::MetaEntity_load:
        auto xml = event.getData().xmlElement;
        loadMetaEntity(xml);
        break;
    }
}

// -----------------------------------------------------------------------------

void StartupPhase::loadMetaEntity(tinyxml2::XMLElement *xml) {
    const char *name;
    xml->QueryStringAttribute("name", &name);
    auto &metaEntity = data::MetaEntitySystem::getInstance().get(name);

    auto &facet =
        MetaEntityFacetSystem::getInstance().create(metaEntity.getId());

    auto gfxElement = xml->FirstChildElement("graphics");
    assert(gfxElement != nullptr);

    auto texFilename = gfxElement->FirstChildElement("texture")->GetText();
    facet.setTexture(texFilename);

    metaEntity.registerFacet(data::MetaEntityFacetKind::Gfx, &facet);
}