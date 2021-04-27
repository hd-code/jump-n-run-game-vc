#include "data/startup-phase.hpp"
#include "core/config.hpp"
#include "data/entity-kind.hpp"
#include "data/event-system.hpp"
#include "data/meta-entity-system.hpp"
#include <assert.h>
#include <string>

using namespace data;

// -----------------------------------------------------------------------------

StartupPhase::StartupPhase()
    : document_(), metaElement_(nullptr), numOfMetaEntities_(0),
      numOfMetaEntitiesLoaded_(0) {}

StartupPhase::~StartupPhase() {}

// -----------------------------------------------------------------------------

void StartupPhase::onEnter() {
    const std::string file = core::Config::dataDir + "meta-entities.xml";
    auto err = document_.LoadFile(file.c_str());
    assert(err == tinyxml2::XML_SUCCESS);

    metaElement_ = document_.FirstChildElement()->FirstChildElement();

    auto nextEntity = metaElement_;
    while (nextEntity != nullptr) {
        numOfMetaEntities_ += 1;
        nextEntity = nextEntity->NextSiblingElement();
    }
}

void StartupPhase::onLeave() { document_.Clear(); }

bool StartupPhase::onRun() {
    if (metaElement_ == nullptr) {
        return false;
    }

    loadMetaEntity();

    numOfMetaEntitiesLoaded_ += 1;
    metaElement_ = metaElement_->NextSiblingElement();

    return metaElement_ != nullptr;
}

// -----------------------------------------------------------------------------

void StartupPhase::loadMetaEntity() {
    const char *name;
    metaElement_->QueryStringAttribute("name", &name);

    auto &metaEntity = MetaEntitySystem::getInstance().create(name);

    auto dataElement = metaElement_->FirstChildElement("data");
    assert(dataElement != nullptr);

    auto kindName = dataElement->FirstChildElement("kind")->GetText();
    auto kind = EntityKind::getEntityKind(kindName);

    auto height = dataElement->FirstChildElement("height")->FloatText();
    auto width = dataElement->FirstChildElement("width")->FloatText();

    metaEntity.init(kind, height, width);

    EventData data;
    data.xmlElement = metaElement_;
    EventSystem::getInstance().fireEvent(EventKind::MetaEntity_load, data);
}