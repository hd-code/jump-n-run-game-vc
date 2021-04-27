#include "core/aabb.hpp"
#include "data/entity-iterator.hpp"
#include "data/entity.hpp"
#include "data/map-system.hpp"
#include "data/map.hpp"
#include <iostream>

namespace testmap {

void main() {
    std::cout << "-- Testing Map" << std::endl;

    data::MapSystem::getInstance().createMap(32.0f, 16.0f);

    data::Entity entities[3] = {
        data::Entity("A", data::EntityKind::Platform,
                     core::Vector2(0.0f, 0.0f)),
        data::Entity("B", data::EntityKind::Player, core::Vector2(6.0f, 7.0f)),
        data::Entity("C", data::EntityKind::Platform,
                     core::Vector2(12.0f, 0.0f)),
    };
    for (auto i = 0; i < 3; ++i) {
        data::MapSystem::getInstance().addEntity(entities[i]);
    }

    auto all = core::AABB(0.0f, 0.0f, 16.0f, 16.0f);
    auto onlyB = core::AABB(4.0f, 4.0f, 8.0f, 8.0f);
    auto none = core::AABB(14.0f, 14.0f, 18.0f, 18.0f);

    auto end = data::MapSystem::getInstance().end();

    std::cout << "should print all:" << std::endl;
    data::EntityIterator it = data::MapSystem::getInstance().begin(all);
    for (; it != end; it = data::MapSystem::getInstance().next(it, all)) {
        it->sayHello();
    }

    std::cout << "should print only B:" << std::endl;
    it = data::MapSystem::getInstance().begin(onlyB);
    for (; it != end; it = data::MapSystem::getInstance().next(it, onlyB)) {
        it->sayHello();
    }

    std::cout << "should print none:" << std::endl;
    it = data::MapSystem::getInstance().begin(none);
    for (; it != end; it = data::MapSystem::getInstance().next(it, none)) {
        it->sayHello();
    }

    for (auto i = 0; i < 3; ++i) {
        data::MapSystem::getInstance().removeEntity(entities[i]);
    }

    data::MapSystem::getInstance().destroyMap();

    std::cout << "-- End Testing Map" << std::endl << std::endl;
}

} // namespace testmap