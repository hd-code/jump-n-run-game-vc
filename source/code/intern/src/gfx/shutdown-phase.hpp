#pragma once

#include "core/singleton.hpp"

// -----------------------------------------------------------------------------

namespace gfx {

class ShutdownPhase : public core::Singleton<ShutdownPhase> {
public:
    bool onRun();

private:
    template <class T> friend class core::Singleton;
    ShutdownPhase();
    ~ShutdownPhase();
};

} // namespace gfx