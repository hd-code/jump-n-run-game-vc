#include "data/load-map-phase.hpp"
#include "core/config.hpp"
#include "data/entity-system.hpp"
#include "data/event-system.hpp"
#include "data/map-system.hpp"
#include "data/meta-entity-system.hpp"
#include <assert.h>
#include <string>

using namespace data;

// -----------------------------------------------------------------------------

LoadMapPhase::LoadMapPhase()
    : document_(), mapElement_(nullptr), entityElement_(nullptr),
      numOfEntities_(0), numOfEntitiesLoaded_(0), mapCreated_(false) {}

LoadMapPhase::~LoadMapPhase() {}

// -----------------------------------------------------------------------------

#pragma warning(disable : 4189)
void LoadMapPhase::onEnter() {
    numOfEntities_ = 0;
    numOfEntitiesLoaded_ = 0;
    mapCreated_ = false;

    const std::string file = core::Config::levelsDir + "level-1.xml";
    auto error = document_.LoadFile(file.c_str());
    assert(error == tinyxml2::XML_SUCCESS);

    mapElement_ = document_.FirstChildElement("map");
    entityElement_ =
        mapElement_->FirstChildElement("entities")->FirstChildElement();

    auto nextEntity = entityElement_;
    while (nextEntity != nullptr) {
        numOfEntities_ += 1;
        nextEntity = nextEntity->NextSiblingElement();
    }
}

void LoadMapPhase::onLeave() { document_.Clear(); }

bool LoadMapPhase::onRun() {
    if (!mapCreated_) {
        loadMap();
        mapCreated_ = true;
        return true;
    }

    if (entityElement_ == nullptr) {
        return false;
    }

    loadEntity();
    numOfEntitiesLoaded_ += 1;
    entityElement_ = entityElement_->NextSiblingElement();

    return entityElement_ != nullptr;
}

// -----------------------------------------------------------------------------

void LoadMapPhase::loadMap() {
    auto height = mapElement_->FirstChildElement("height")->FloatText();
    auto width = mapElement_->FirstChildElement("width")->FloatText();
    MapSystem::getInstance().createMap(width, height);
}

void LoadMapPhase::loadEntity() {
    const char *name;
    entityElement_->QueryStringAttribute("name", &name);

    auto &entity = EntitySystem::getInstance().create(name);

    auto metaEntityName =
        entityElement_->FirstChildElement("meta-entity")->GetText();
    auto &metaEntity = MetaEntitySystem::getInstance().get(metaEntityName);

    auto dataElement = entityElement_->FirstChildElement("data");
    assert(dataElement != nullptr);

    auto positionElement = dataElement->FirstChildElement("position");
    assert(positionElement != nullptr);

    auto x = positionElement->FirstChildElement("x")->FloatText();
    auto y = positionElement->FirstChildElement("y")->FloatText();

    entity.init(metaEntity, x, y);

    EventData data;
    data.xmlElement = entityElement_;
    EventSystem::getInstance().fireEvent(EventKind::Entity_load, data);

    MapSystem::getInstance().addEntity(entity);
}