#pragma once

#include "screeps/room-object.hpp"
#include "screeps/types.hpp"

namespace Screeps {
    class Structure : public RoomObject {
      public:
        enum class Type {
            Spawn,
            Extension,
            Road,
            Wall,
            Rampart,
            KeeperLair,
            Portal,
            Controller,
            Link,
            Storage,
            Tower,
            Observer,
            PowerBank,
            PowerSpawn,
            Extractor,
            Lab,
            Terminal,
            Container,
            Nuker
        };

        int hits() const;
        int hitsMax() const;
        Id id() const;
        Type structureType() const;

        Error destroy();
        bool isActive();
        Error notifyWhenAttacked(bool enabled);
    };
} // namespace Screeps
