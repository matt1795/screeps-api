// Game Object Wrapper
//
// Author: Matthew Knight
// File Name: game.hpp
// Date: 2019-06-20

#pragma once

#include <emscripten/val.h>

#include "screeps/constants.hpp"
#include "screeps/construction-site.hpp"
#include "screeps/creep.hpp"
#include "screeps/enums.hpp"
#include "screeps/flag.hpp"
#include "screeps/order.hpp"
#include "screeps/power-creep.hpp"
#include "screeps/room.hpp"
#include "screeps/spawn.hpp"
#include "screeps/structure.hpp"
#include "screeps/transaction.hpp"
#include "screeps/types.hpp"

#include <optional>
#include <string>
#include <unordered_map>

namespace Screeps {
    namespace Game {
        std::unordered_map<Id, ConstructionSite> const& constructionSites();
        std::unordered_map<Creep::Name, Creep> const& creeps();
        std::unordered_map<Flag::Name, Flag> const& flags();
        std::unordered_map<PowerCreep::Name, PowerCreep> const& powerCreeps();
        std::unordered_map<Room::Name, Room> const& rooms();
        std::unordered_map<Spawn::Name, Spawn> const& spawns();
        std::unordered_map<Id, Structure> const& structures();

        namespace Cpu {
            int limit();
            int tickLimit();
            int bucket();
            // TODO: shard limits
        }; // namespace Cpu

        namespace Gcl {
            int level();
            int progress();
            int progressTotal();
        }; // namespace Gcl

        namespace Gpl {
            int level();
            int progress();
            int progressTotal();
        }; // namespace Gpl

        namespace Shard {
            std::string name();
            std::string type();
            bool ptr();
        }; // namespace Shard

        namespace Map {
            std::unordered_map<std::string, std::string>
            describeExits(Room const& room);
            // TODO: pathfinding options
            Find findExit(Room const& fromRoom, Room const& toRoom);
            // TODO: pathfinding options
            std::vector<std::pair<Find, std::string>>
            findRoute(Room const& fromRoom, Room const& toRoom);
            int getRoomLinearDistance(Room const& room1, Room const& room2,
                                      bool continuous = false);
            Room::Terrain getRoomTerrain(Room const& room);
            int getWorldSize();
            bool isRoomAvailable(Room const& room);
        }; // namespace Map

        namespace Market {
            int credits();
            std::vector<Transaction> incomingTransactions();
            std::vector<Transaction> outgoingTransactions();
            std::unordered_map<std::string, Order> orders();
            int calcTransactionCost(int amount, Room const& room1,
                                    Room const& room2);
            Error cancelOrder(Order::Id const& id);
            Error changeOrderPrice(Order::Id const& id, int newPrice);
            Error createOrder(Order::Type const& type, Resource const& resource,
                              int price, int totalAmount,
                              std::string const& roomName);
            Error deal(Order::Id const& id, int amount, Room const& yourRoom);
            Error extendOrder(Order::Id const& id, int addAmount);
            // TODO: getAllOrders
            Order getOrderById(Order::Id const& id);
        }; // namespace Market

        int time();
        emscripten::val getObjectById(Id const& id);
        void notify(std::string const& message, unsigned int groupInterval = 0);
    }; // namespace Game
} // namespace Screeps
