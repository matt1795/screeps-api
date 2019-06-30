#pragma once

#include "screeps/room-position.hpp"
#include "screeps/room.hpp"

namespace Screeps {
    class RoomObject {
        Room& room;
        RoomPosition pos;

        RoomObject(Room& room, RoomPosition const& pos)
            : room(room)
            , pos(pos) {}
    };
} // namespace Screeps
