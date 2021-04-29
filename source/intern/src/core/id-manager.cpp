#include "core/id-manager.hpp"
#include <assert.h>

using namespace core;

// -----------------------------------------------------------------------------

IdManager::IdManager() : mapIdStringToId_(), idStrings_() {}

IdManager::~IdManager() { mapIdStringToId_.clear(); }

// -----------------------------------------------------------------------------

IdManager::Id IdManager::add(IdString &idString) {
    if (hasId(idString)) {
        return mapIdStringToId_[idString];
    }
    Id newId = (Id)idStrings_.size();
    idStrings_.push_back(idString);
    mapIdStringToId_.insert(MapEntry(idString, newId));
    return newId;
}

void IdManager::clear() {
    mapIdStringToId_.clear();
    idStrings_.clear();
}

// -----------------------------------------------------------------------------

bool IdManager::hasId(IdString &id) const {
    return mapIdStringToId_.find(id) != mapIdStringToId_.end();
}

bool IdManager::hasId(Id id) const { return id < idStrings_.size(); }

// -----------------------------------------------------------------------------

IdManager::Id IdManager::getId(IdString &id) const {
    auto entry = mapIdStringToId_.find(id);
    assert(entry != mapIdStringToId_.end());
    return entry->second;
}

IdManager::IdString &IdManager::getId(Id id) const {
    assert(hasId(id));
    return idStrings_[id];
}

// -----------------------------------------------------------------------------

unsigned int IdManager::size() const { return (unsigned int)idStrings_.size(); }