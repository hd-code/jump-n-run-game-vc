#include "gfx/shutdown-phase.hpp"

using namespace gfx;

// -----------------------------------------------------------------------------

bool ShutdownPhase::onRun() {
    // return AssetSystem::getInstance().unloadStaticAssets();
    return true;
}