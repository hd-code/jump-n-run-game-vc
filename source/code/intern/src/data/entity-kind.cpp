#include "data/entity-kind.hpp"

using namespace data;

// -----------------------------------------------------------------------------

std::map<std::string, EntityKind::Enum> EntityKind::mapNameToKind_ = {
    {"player", Player},
    {"platform", Platform},
    {"obstacle", Obstacle},
    {"other", Other},
};

EntityKind::Enum EntityKind::getEntityKind(const std::string &name) {
    auto iterator = mapNameToKind_.find(name);
    if (iterator == mapNameToKind_.end()) {
        return Other;
    }
    return iterator->second;
}