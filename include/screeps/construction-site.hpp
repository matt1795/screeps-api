// Construction site class
//
// Author: Matthew Knight
// File Name: construction-site.hpp
// Date: 2019-06-28

#pragma once

#include "screeps/enums.hpp"
#include "screeps/room-object.hpp"
#include "screeps/types.hpp"

#include <emscripten/val.h>

namespace Screeps {
    struct ConstructionSite : public RoomObject {
        ConstructionSite(emscripten::val object)
            : RoomObject(object) {}
        Id id() const;
        bool my() const;
        std::string owner() const;
        int progress() const;
        int progressTotal() const;
        StructureType structureType() const;

        Error remove();
    };
} // namespace Screeps
