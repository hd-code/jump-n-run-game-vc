#include "gfx/startup-phase.hpp"

using namespace gfx;

// -----------------------------------------------------------------------------

bool StartupPhase::onRun() {
    // return AssetSystem::getInstance().loadStaticAssets();
    return true;
}