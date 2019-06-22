// Game Object Wrapper
//
// Author: Matthew Knight
// File Name: game.hpp
// Date: 2019-06-20

#include <emscripten/val.h>

#include <string>
#include <unordered_map>

namespace Screeps {
	std::unordered_map<std::string, ConstructionSite> Game::constructionSites() {
		return {};
	}

	std::unordered_map<std::string, Creep> Game::creeps() { return {}; }

	std::unordered_map<std::string, Flag> Game::flags() { return {}; }

	std::unordered_map<std::string, PowerCreep> Game::powerCreeps() { return {}; }

	std::unordered_map<std::string, Room> Game::rooms() { return {}; }

	std::unordered_map<std::string, Spawn> Game::spawns() { return {}; }

	std::unordered_map<std::string, Structure> Game::structures() { return {}; }

	int Game::Cpu::limit() { return game["cpu"]["limit"].as<int>(); }

	int Game::Cpu::tickLimit() {
		return game["cpu"]["tickLimit"].as<int>();
	}

	int Game::Cpu::bucket() { return game["cpu"]["bucket"].as<int>(); }
	
	int Game::Gcl::level() { return game["gcl"]["level"].as<int>(); }

	int Game::Gcl::progress() { return game["gcl"]["progress"].as<int>(); }

	int Game::Gcl::progressTotal() {
		return game["gcl"]["progressTotal"].as<int>();
	}

	class Gpl {
		static int Game::Gpl::level() { return game["gpl"]["level"].as<int>(); }

		static int progress() { return game["gpl"]["progress"].as<int>(); }

		static int progressTotal() {
			return game["gpl"]["progressTotal"].as<int>();
		}
	};

	class Shard {
		static std::string name() {
			return game["shard"]["name"].as<std::string>();
		}

		static std::string type() {
			return game["shard"]["type"].as<std::string>();
		}

		static bool ptr() { return game["shard"]["ptr"].as<bool>(); }
	};

	class Map {
		static std::unordered_map<std::string, std::string>
		describeExits(std::string const& roomName) {
			return {};
		}

		// TODO: pathfinding options
		static Find findExit(std::string const& fromRoom,
								std::string const& toRoom) {}

		// TODO: pathfinding options
		static std::vector<std::pair<Find, std::string>>
		findRoute(std::string const& fromRoom, std::string const& toRoom) {}

		static int getRoomLinearDistance(std::string const& roomName1,
											std::string const& roomName2,
											bool continuous = false) {}

		static Terrain getRoomTerrain(std::string const& roomName) {}

		static int getWorldSize() {}

		static bool isRoomAvailable(std::string const& roomName) {}
	};

	class Market {
		static int credits();

		static std::vector<Transaction> incomingTransactions();
		static std::vector<Transaction> outgoingTransactions();
		static std::unordered_map<std::string, Order> orders();
		static int calcTransactionCost(int amount,
										std::string const& roomName1,
										std::string const& roomName2);
		static Error cancelOrder(std::string const& orderId);
		static Error changeOrderPrice(std::string const& orderId,
										int newPrice);
		static Error createOrder(std::string const& type,
									std::string const& resourceType, int price,
									int totalAmount,
									std::string const& roomName);
		static Error deal(std::string const& orderId, int amount,
							std::string const& yourRoomName);
		static Error extendOrder(std::string const& orderId, int addAmount);
		// TODO: getAllOrders
		static Order getOrderById(std::string const& id);
	};

	int time() { return game["time"].as<int>(); }

	emscripten::val getObjectById(std::string const& id) {
		return game.call<emscripten::val>("getObjectById", id);
	}

	void notify(std::string const& message,
				unsigned int groupInterval = 0) {
		game.call<void>("notify", message, groupInterval);
	}
} // namespace Screeps
