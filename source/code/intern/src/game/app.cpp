#include "game/app.hpp"
#include "game/load-map-phase.hpp"
#include "game/main-menu-phase.hpp"
#include "game/play-phase.hpp"
#include "game/shutdown-phase.hpp"
#include "game/startup-phase.hpp"
#include "game/unload-map-phase.hpp"
#include <stdexcept>

using namespace game;

// -----------------------------------------------------------------------------

App::App() : phaseIndex_(PhaseKind::Startup) {
    // FRAGE: ist hier ein cleanup nötig?
    phases_[PhaseKind::Startup] = &StartupPhase::getInstance();
    phases_[PhaseKind::MainMenu] = &MainMenuPhase::getInstance();
    phases_[PhaseKind::LoadMap] = &LoadMapPhase::getInstance();
    phases_[PhaseKind::Play] = &PlayPhase::getInstance();
    phases_[PhaseKind::UnloadMap] = &UnloadMapPhase::getInstance();
    phases_[PhaseKind::Shutdown] = &ShutdownPhase::getInstance();
}

App::~App() {}

// -----------------------------------------------------------------------------

void App::start(unsigned int width, unsigned int height) {
    // window.create(sf::VideoMode(width, height), "Jump n Run Game – VC");
}

void App::exit() {
    // window.close();
}

void App::run() {
    getPhase()->onEnter();
    while (phaseIndex_ != PhaseKind::Exit) {
        handleEventQueue();
        onRun();
    }
}

// -----------------------------------------------------------------------------

void App::handleEventQueue() {
    // sf::Event event;
    // while (window.pollEvent(event)) {
    //     if (event.type == sf::Event::Closed)
    //         currentPhaseIndex = Phase::Exit;
    //         // window.close();
    // }
}

void App::onRun() {
    PhaseKind::Enum nextPhase = getPhase()->onRun();
    if (nextPhase != phaseIndex_) {
        onTransition(nextPhase);
    }
}

void App::onTransition(PhaseKind::Enum nextPhase) {
    getPhase()->onLeave();

    phaseIndex_ = nextPhase;
    if (nextPhase == PhaseKind::Exit) {
        return;
    }

    getPhase()->onEnter();
}

// -----------------------------------------------------------------------------

BasePhase *App::getPhase() const { return phases_[phaseIndex_]; }