#pragma once

#include "screeps/enums.hpp"
#include "screeps/room-object.hpp"

namespace Screeps {
    class Mineral {
        public:
            int density() const;
            int mineralAmount() const;
            Resource mineralType() const;
    };
}
