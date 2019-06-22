// Room Class
//
// Author: Matthew Knight
// File Name: room.hpp
// Date: 2019-06-21

#pragma once

#include "screeps/game.hpp"

#include <emscripten/val.h>

namespace Screeps {
	class Room {
		emscripten::val object;
	public:
		Room(emscripten::val&& obj) : object(obj) {}
		Room(std::string const& name) : Room(Game::Rooms[name]) {}
		
		Name name() const {}
	};
}
