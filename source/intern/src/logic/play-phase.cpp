#include "logic/play-phase.hpp"
#include "core/aabb.hpp"
#include "data/entity-system.hpp"
#include "data/event-system.hpp"
#include "data/map-system.hpp"

using namespace logic;

// -----------------------------------------------------------------------------

PlayPhase::PlayPhase() : nextCameraMove_(None), leaveLevel_(false) {}

PlayPhase::~PlayPhase() {}

// -----------------------------------------------------------------------------

void PlayPhase::onEnter() {
    leaveLevel_ = false;

    // focus initially on the player
    auto &player = data::EntitySystem::getInstance().get("player");
    cameraPosition_ = player.getAABB().getCenter();

    data::EventSystem::getInstance().addEventListener(*this);
}

void PlayPhase::onLeave() {
    data::EventSystem::getInstance().removeEventListener(*this);
}

bool PlayPhase::onRun() {
    moveCamera();
    return !leaveLevel_;
}

// -----------------------------------------------------------------------------

void PlayPhase::onEvent(const data::Event &event) {
    switch (event.getKind()) {
    case data::EventKind::UserInput:
        switch (event.getData().key) {
        case core::UserInput::Escape:
            leaveLevel_ = true;
            break;
        case core::UserInput::Up:
            nextCameraMove_ = Up;
            break;
        case core::UserInput::Down:
            nextCameraMove_ = Down;
            break;
        case core::UserInput::Left:
            nextCameraMove_ = Left;
            break;
        case core::UserInput::Right:
            nextCameraMove_ = Right;
            break;
        }
        break;
    }
}

// -----------------------------------------------------------------------------

core::Vector2 &PlayPhase::getCameraPosition() { return cameraPosition_; }
const core::Vector2 &PlayPhase::getCameraPosition() const {
    return cameraPosition_;
}

// -----------------------------------------------------------------------------

void PlayPhase::moveCamera() {
    auto position = cameraPosition_;

    switch (nextCameraMove_) {
    case Up:
        position.setY(position.getY() - cameraMoveWidth_);
        break;
    case Down:
        position.setY(position.getY() + cameraMoveWidth_);
        break;
    case Left:
        position.setX(position.getX() - cameraMoveWidth_);
        break;
    case Right:
        position.setX(position.getX() + cameraMoveWidth_);
        break;
    }
    nextCameraMove_ = None;

    if (data::MapSystem::getInstance().getMapSize().contains(position)) {
        cameraPosition_ = position;
    }
}