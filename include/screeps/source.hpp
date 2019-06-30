#pragma once

#include "screeps/room-object.hpp"

namespace Screeps {
    class Source : public RoomObject {
      public:
        int energy() const;
        int energyCapacity() const;
        Id id() const;
        int ticksToRegeneration() const;
    };
} // namespace Screeps
