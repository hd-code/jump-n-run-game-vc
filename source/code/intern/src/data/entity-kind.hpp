#pragma once

namespace data {

struct EntityKind {
    typedef enum {
        Player,
        Platform,
        Obstacle,
        Length,
    } Enum;
};

}