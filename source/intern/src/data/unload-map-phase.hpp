#pragma once

#include "core/singleton.hpp"

// -----------------------------------------------------------------------------

namespace data {

class UnloadMapPhase : public core::Singleton<UnloadMapPhase> {
  public:
    void onEnter();
    void onLeave();
    bool onRun();

  private:
    template <class T> friend class core::Singleton;
    UnloadMapPhase();
    ~UnloadMapPhase();
};

} // namespace data