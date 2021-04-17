#include "data/entity-folder.hpp"

using namespace data;

// -----------------------------------------------------------------------------

EntityFolder::EntityFolder() {}
EntityFolder::~EntityFolder() { entities_.clear(); }

// -----------------------------------------------------------------------------

EntityList &EntityFolder::getEntities() { return entities_; }

// -----------------------------------------------------------------------------

void EntityFolder::addEntity(Entity &entity) { entities_.push_back(entity); }
void EntityFolder::removeEntity(Entity &entity) { entities_.remove(entity); }