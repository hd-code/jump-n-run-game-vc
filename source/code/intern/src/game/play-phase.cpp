#include "game/play-phase.hpp"

#include "data/entity.hpp"
#include "data/map-system.hpp"

#include <iostream>

using namespace game;

// -----------------------------------------------------------------------------

PlayPhase::PlayPhase() {}
PlayPhase::~PlayPhase() {}

// -----------------------------------------------------------------------------

void PlayPhase::onEnter() { std::cout << "PlayPhase onEnter" << std::endl; }

void PlayPhase::onLeave() { std::cout << "PlayPhase onLeave" << std::endl; }

int PlayPhase::onRun() {
    std::cout << "PlayPhase onRun" << std::endl;

    data::MapSystem::getInstance().initMap(40, 40);

    std::cout << std::endl << "-- Testing Map" << std::endl;

    data::Entity entities[3] = {data::Entity("A"), data::Entity("B"),
                                data::Entity("C")};
    for (auto i = 0; i < 3; ++i) {
        data::MapSystem::getInstance().addEntity(entities[i]);
    }
    for (auto i = 0; i < 3; ++i) {
        data::MapSystem::getInstance().moveEntity(entities[i]);
    }
    for (auto i = 0; i < 3; ++i) {
        data::MapSystem::getInstance().removeEntity(entities[i]);
    }
    std::cout << "-- Ende Testing Map" << std::endl << std::endl;

    return Phase::UnloadMap;
}