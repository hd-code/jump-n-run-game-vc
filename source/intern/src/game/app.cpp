#include "game/app.hpp"
#include "data/event-system.hpp"
#include "data/event.hpp"
#include "game/load-map-phase.hpp"
#include "game/main-menu-phase.hpp"
#include "game/play-phase.hpp"
#include "game/shutdown-phase.hpp"
#include "game/startup-phase.hpp"
#include "game/unload-map-phase.hpp"

using namespace game;

// -----------------------------------------------------------------------------

App::App() : phaseIndex_(PhaseKind::Startup) {
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
    window_.create(sf::VideoMode(width, height), "Jump 'n' Run HD");
}

void App::exit() {
    window_.clear();
    window_.close();
}

void App::run() {
    getPhase()->onEnter(window_);
    while (phaseIndex_ != PhaseKind::Exit) {
        handleEventQueue();
        onRun();
    }
}

// -----------------------------------------------------------------------------

void App::handleEventQueue() {
    auto eventKind = data::EventKind::UserInput;
    auto data = data::EventData();

    sf::Event event;
    while (window_.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            data.key = core::UserInput::Escape;
            data::EventSystem::getInstance().addEvent(eventKind, data);
            break;

        case sf::Event::KeyPressed:
            switch (event.key.code) {
            case sf::Keyboard::Escape:
                data.key = core::UserInput::Escape;
                data::EventSystem::getInstance().addEvent(eventKind, data);
                break;
            case sf::Keyboard::Enter:
                data.key = core::UserInput::Enter;
                data::EventSystem::getInstance().addEvent(eventKind, data);
                break;
            case sf::Keyboard::Up:
                data.key = core::UserInput::Up;
                data::EventSystem::getInstance().addEvent(eventKind, data);
                break;
            case sf::Keyboard::Down:
                data.key = core::UserInput::Down;
                data::EventSystem::getInstance().addEvent(eventKind, data);
                break;
            case sf::Keyboard::Left:
                data.key = core::UserInput::Left;
                data::EventSystem::getInstance().addEvent(eventKind, data);
                break;
            case sf::Keyboard::Right:
                data.key = core::UserInput::Right;
                data::EventSystem::getInstance().addEvent(eventKind, data);
                break;
            }
            break;
        }
    }

    data::EventSystem::getInstance().fireEvents();
}

void App::onRun() {
    auto nextPhase = getPhase()->onRun();
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

    getPhase()->onEnter(window_);
}

// -----------------------------------------------------------------------------

BasePhase *App::getPhase() const { return phases_[phaseIndex_]; }