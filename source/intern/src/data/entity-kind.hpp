#pragma once

#include <map>
#include <string>

namespace data {

struct EntityKind {
    typedef enum {
        Player,
        Platform,
        Obstacle,
        Other,
        Length,
    } Enum;

    static Enum getEntityKind(const std::string &name);

  private:
    static std::map<std::string, EntityKind::Enum> mapNameToKind_;
};

} // namespace data