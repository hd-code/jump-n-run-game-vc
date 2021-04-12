#pragma once

#include "core/singleton.hpp"

// -----------------------------------------------------------------------------

namespace gfx {

class StartupPhase : public core::Singleton<StartupPhase> {
public:
    bool onRun();

private:
    template <class T> friend class core::Singleton;
    StartupPhase();
    ~StartupPhase();
};

} // namespace gfx