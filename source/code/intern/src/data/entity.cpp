#include "data/entity.hpp"
#include <iostream>

using namespace data;

// -----------------------------------------------------------------------------

Entity::Entity(std::string name, EntityKind::Enum kind, core::Vector2 pos)
    : name_(name), kind_(kind), pos_(pos) {}
Entity::~Entity() {}

// -----------------------------------------------------------------------------

core::Vector2 Entity::getPosition() const { return pos_; }
EntityKind::Enum Entity::getKind() const { return kind_; }

// -----------------------------------------------------------------------------

void Entity::sayHello() { std::cout << "Hello, I'm " << name_ << std::endl; }
void Entity::sayLink() { std::cout << "Link at: " << &link_ << std::endl; }