#pragma once

#include "screeps/room-position.hpp"
#include "screeps/room.hpp"

#include <emscripten/val.h>

#include <memory>

namespace Screeps {
    class RoomObject {
        emscripten::val object;
        public:
        RoomObject(emscripten::val objet) : object(object) {}

        Room& room() const;
        RoomPosition& pos() const;
    };
} // namespace Screeps
