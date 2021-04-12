#include "game/app.hpp"

#include "game/load-map-phase.hpp"
#include "game/main-menu-phase.hpp"
#include "game/play-phase.hpp"
#include "game/shutdown-phase.hpp"
#include "game/startup-phase.hpp"
#include "game/unload-map-phase.hpp"
#include <stdexcept>

// for testing
#include "gfx/tmp.hpp"
#include "gui/tmp.hpp"
#include "logic/tmp.hpp"
#include <iostream>
//------------

using namespace game;

// -----------------------------------------------------------------------------

App::App() : currentPhaseIndex(Phase::Startup) {
    // FRAGE: ist hier ein cleanup überhaupt nötig?
    phases[Phase::Startup] = &StartupPhase::getInstance();
    phases[Phase::MainMenu] = &MainMenuPhase::getInstance();
    phases[Phase::LoadMap] = &LoadMapPhase::getInstance();
    phases[Phase::Play] = &PlayPhase::getInstance();
    phases[Phase::UnloadMap] = &UnloadMapPhase::getInstance();
    phases[Phase::Shutdown] = &ShutdownPhase::getInstance();

    // MainMenuPhase::getInstance().setWindow(window);
}

App::~App() {}

// -----------------------------------------------------------------------------

void App::start(unsigned int width, unsigned int height) {
    // window.create(sf::VideoMode(width, height), "Jump n Run Game – VC");
}

void App::exit() {
    // window.close();

    // for testing
    std::cout << "Testing access to other projects:" << std::endl;
    gfx::sayHello();
    gui::sayHello();
    logic::sayHello();
    //------------
}

void App::run() {
    getCurrentPhase()->onEnter();
    while (currentPhaseIndex != Phase::Exit) {
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
    int nextPhase = getCurrentPhase()->onRun();
    if (nextPhase != currentPhaseIndex) {
        onTransition(nextPhase);
    }
}

void App::onTransition(int nextPhase) {
    getCurrentPhase()->onLeave();

    currentPhaseIndex = nextPhase;
    if (nextPhase == Phase::Exit) {
        return;
    }

    getCurrentPhase()->onEnter();
}

// -----------------------------------------------------------------------------

BasePhase *App::getCurrentPhase() { return phases[currentPhaseIndex]; }