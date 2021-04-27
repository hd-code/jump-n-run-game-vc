#pragma once

#include "core/singleton.hpp"
#include "tinyxml2/tinyxml2.h"

// -----------------------------------------------------------------------------

namespace data {

class StartupPhase : public core::Singleton<StartupPhase> {
  public:
    void onEnter();
    void onLeave();
    bool onRun();

  private:
    template <class T> friend class core::Singleton;
    StartupPhase();
    ~StartupPhase();

    void loadMetaEntity();

    tinyxml2::XMLDocument document_;
    tinyxml2::XMLElement *metaElement_;

    unsigned int numOfMetaEntities_;
    unsigned int numOfMetaEntitiesLoaded_;
};

} // namespace data