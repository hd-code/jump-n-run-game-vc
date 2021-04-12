#include "data/entity.hpp"

#include <iostream>

using namespace data;

// -----------------------------------------------------------------------------

Entity::Entity(std::string name) : name(name) {}
Entity::~Entity() {}

// -----------------------------------------------------------------------------

void Entity::sayHello() {
    std::cout << "Hello, I'm " << name << std::endl;
}