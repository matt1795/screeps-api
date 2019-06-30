#pragma once

#include <string>

namespace Screeps {
    struct RoomPosition {
        std::string roomName;
        int x;
        int y;

        // TODO: optional name for spawns
        //Error createContstructionSite(Structure::Type type);
        // TODO:
        // createFlag
        // findClosestByPath
        // findCLosestByRange
        // findInRange
        // findPathTo
        // getDirectionTo
        // getRangeTo
        // inRangeTo
        // isEqualTo
        // isNearTo
        // look
        // lookFor
    };
} // namespace Screeps
