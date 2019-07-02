#pragma once

#include "screeps/room-object.hpp"

#include <emscripten/val.h>

#include <string>

namespace Screeps {
    class Spawn : public RoomObject {
      public:
        using Name = std::string;
        inline static int const hits = 5000;
        inline static int const energyStart = 300;
        inline static int const energyCapacity = 300;
        inline static int const spawnTime = 3;
        inline static double const renewRatio = 1.2;

        Spawn(emscripten::val object)
            : RoomObject(object) {}
    };
} // namespace Screeps
