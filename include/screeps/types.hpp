#pragma once

#include "screeps/room-position.hpp"

#include <string>
#include <vector>

namespace Screeps {
    using Id = std::string;
    using Path = std::vector<RoomPosition>;

    class RoomObject;
    class Structure;
}
