// Room Class
//
// Author: Matthew Knight
// File Name: room.hpp
// Date: 2019-06-21

#pragma once

#include "screeps/game.hpp"
#include "screeps/controller.hpp"
#include "screeps/storage.hpp"
#include "screeps/terminal.hpp"
#include "screeps/types.hpp"
#include "screeps/structure.hpp"

namespace Screeps {
    class Room {
        emscripten::val object;

      public:
        using Name = std::string;
        using Terrain = std::array<std::array<uint8_t, 50>, 50>;

        Room(emscripten::val&& obj);
        Room(std::string const& name);

        // readable attributes
        Controller controller();
        int energyCapacityAvailable() const;
        Name name() const;
        Storage storage();
        Terminal& terminal();
        static std::string serializePath(Path const& path);
        static Path deserializePath(std::string const& path);
        Error createConstructionSite(int x, int y, StructureType type);
        Error createConstructionSite(RoomPosition const& pos,
                                     StructureType type);
        std::vector<RoomObject> find(Find f);
        Find findExitTo(Room const& room);
        Find findExitTo(std::string const& room);
        Terrain getTerrain();
        // TODO:
        // createFlag
        // visual()
        // findPath
        // getEventLog
        // getPositionAt
        // lookAt
        // lookAtArea
        // lookForAt
        // lookForAtArea
    };
} // namespace Screeps
