// Game Object Wrapper
//
// Author: Matthew Knight
// File Name: game.hpp
// Date: 2019-06-20

#pragma once

#include <emscripten/val.h>

#include <string>
#include <unordered_map>

namespace Screeps {
    class Game {
        inline static emscripten::val game = emscripten::val::global("Game");

      public:
		/**
		 *
		 */
        static std::unordered_map<Id, ConstructionSite> constructionSites();

		/**
		 *
		 */
        static std::unordered_map<Creep::Name, Creep> creeps();
        static std::unordered_map<std::string, Flag> flags();
        static std::unordered_map<std::string, PowerCreep> powerCreeps();
        static std::unordered_map<std::string, Room> rooms();
        static std::unordered_map<std::string, Spawn> spawns();
        static std::unordered_map<std::string, Structure> structures();

        class Cpu {
            static int limit();
            static int tickLimit();
            static int bucket();
            // TODO: shard limits
        };

        class Gcl {
            static int level();
            static int progress();
            static int progressTotal(); 
        };

        class Gpl {
            static int level();
            static int progress();
            static int progressTotal(); 
        };

        class Shard {
            static std::string name();
            static std::string type();
            static bool ptr();
        };

        class Map {
            static std::unordered_map<std::string, std::string>
            describeExits(Room const& room);
            // TODO: pathfinding options
            static Find findExit(Room const& fromRoom,
                                 Room const& toRoom);
            // TODO: pathfinding options
            static std::vector<std::pair<Find, std::string>>
            findRoute(Room const& fromRoom, Room const& toRoom);
            static int getRoomLinearDistance(Room const& room1,
                                             Room const& room2,
                                             bool continuous = false);
            static Terrain getRoomTerrain(Room const& room);
            static int getWorldSize();
            static bool isRoomAvailable(Room const& room);
        };

        class Market {
            static int credits();
            static std::vector<Transaction> incomingTransactions();
            static std::vector<Transaction> outgoingTransactions();
            static std::unordered_map<std::string, Order> orders();
            static int calcTransactionCost(int amount,
                                           Room const& room1,
                                           Room const& room2);
            static Error cancelOrder(Order::Id const& id);
            static Error changeOrderPrice(Order::Id const& id,
                                          int newPrice);
            static Error createOrder(Order::Type const& type,
                                     Resource const& resource, int price,
                                     int totalAmount,
                                     std::string const& roomName);
            static Error deal(Order::Id const& id, int amount,
                              Room const& yourRoom);
            static Error extendOrder(Order::Id const& id, int addAmount);
            // TODO: getAllOrders
            static Order getOrderById(Order::Id const& id);
        };

        static int time();
        static emscripten::val getObjectById(Id const& id);
        static void notify(std::string const& message,
                    unsigned int groupInterval = 0);
    };
} // namespace Screeps
