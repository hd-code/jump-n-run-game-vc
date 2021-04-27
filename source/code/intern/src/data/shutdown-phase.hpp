#pragma once

#include "core/singleton.hpp"

// -----------------------------------------------------------------------------

namespace data {

class ShutdownPhase : public core::Singleton<ShutdownPhase> {
  public:
    void onEnter();
    void onLeave();
    bool onRun();

  private:
    template <class T> friend class core::Singleton;
    ShutdownPhase();
    ~ShutdownPhase();
};

} // namespace data