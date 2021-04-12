#include "data/entity-folder.hpp"

using namespace data;

// -----------------------------------------------------------------------------

EntityFolder::EntityFolder(Sector *sector) : sector(sector) {}

EntityFolder::~EntityFolder() { sector = nullptr; }

// -----------------------------------------------------------------------------

void EntityFolder::add(Entity &entity) { entities.push(entity); }

void EntityFolder::remove(Entity &entity) { entities.remove(entity); }