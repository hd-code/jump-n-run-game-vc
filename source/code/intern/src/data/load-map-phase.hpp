#pragma once

#include "core/singleton.hpp"
#include "tinyxml2/tinyxml2.h"

// -----------------------------------------------------------------------------

namespace data {

class LoadMapPhase : public core::Singleton<LoadMapPhase> {
  public:
    void onEnter();
    void onLeave();
    bool onRun();

  private:
    template <class T> friend class core::Singleton;
    LoadMapPhase();
    ~LoadMapPhase();

    void loadMap();
    void loadEntity();

    tinyxml2::XMLDocument document_;
    tinyxml2::XMLElement *mapElement_;
    tinyxml2::XMLElement *entityElement_;

    unsigned int numOfEntities_;
    unsigned int numOfEntitiesLoaded_;

    bool mapCreated_;
};

} // namespace data