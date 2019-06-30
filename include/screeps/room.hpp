// Room Class
//
// Author: Matthew Knight
// File Name: room.hpp
// Date: 2019-06-21

#pragma once

#include "screeps/game.hpp"

#include <emscripten/val.h>

#include <array>

namespace Screeps {
    class Room {
        emscripten::val object;

      public:
        using Name = std::string;
        using Terrain = std::array<std::array<uint8_t, 50>, 50>;

        Room(emscripten::val&& obj);
        Room(std::string const& name);

        Name name() const;
    };
} // namespace Screeps
