#pragma once

#include "screeps/room-object.hpp"
#include "screeps/types.hpp"

#include <emscripten/val.h>

namespace Screeps {
    class Structure : public RoomObject {
      public:
        Structure(emscripten::val object)
            : RoomObject(object) {}
        int hits() const;
        int hitsMax() const;
        Id id() const;
        StructureType structureType() const;

        Error destroy();
        bool isActive();
        Error notifyWhenAttacked(bool enabled);
    };
} // namespace Screeps
