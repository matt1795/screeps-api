// Construction site class
//
// Author: Matthew Knight
// File Name: construction-site.hpp
// Date: 2019-06-28

#pragma once

#include "screeps/enums.hpp"
#include "screeps/room-object.hpp"
#include "screeps/types.hpp"

namespace Screeps {
    class ConstructionSite : public RoomObject {
      public:
        Id id() const;
        bool my() const;
        std::string owner() const;
        int progress() const;
        int progressTotal() const;
        Structure::Type structureType() const;

        Error remove();
    };
} // namespace Screeps
