// Game Object Wrapper
//
// Author: Matthew Knight
// File Name: game.hpp
// Date: 2019-06-20

#include "screeps/game.hpp"

#include "screeps/constants.hpp"
#include "screeps/util.hpp"

#include <emscripten/val.h>

#include <optional>
#include <string>
#include <unordered_map>

namespace Screeps {
    namespace {
        emscripten::val game = emscripten::val::global("Game");
        std::optional<std::unordered_map<Id, ConstructionSite>>
            constructionSitesOptional;
        std::optional<std::unordered_map<Creep::Name, Creep>> creepsOptional;
        std::optional<std::unordered_map<Room::Name, Room>> roomsOptional;
        std::optional<std::unordered_map<Spawn::Name, Spawn>> spawnsOptional;
        std::optional<std::unordered_map<Id, Structure>> structuresOptional;
    } // namespace

    namespace Game {
        std::unordered_map<Id, ConstructionSite> const& constructionSites() {
            if (!constructionSitesOptional)
                constructionSitesOptional = mapFromJsObject<ConstructionSite>(
                    game["constructionSites"]);

            return *constructionSitesOptional;
        }

        std::unordered_map<Creep::Name, Creep> const& creeps() {
            if (!creepsOptional)
                creepsOptional = mapFromJsObject<Creep>(game["creeps"]);

            return *creepsOptional;
        }

        std::unordered_map<Room::Name, Room> const& rooms() {
            if (!roomsOptional)
                roomsOptional = mapFromJsObject<Room>(game["rooms"]);

            return *roomsOptional;
        }

        std::unordered_map<Spawn::Name, Spawn> const& spawns() {
            if (!spawnsOptional)
                spawnsOptional = mapFromJsObject<Spawn>(game["spawns"]);

            return *spawnsOptional;
        }

        std::unordered_map<Id, Structure> const& structures() {
            if (!structuresOptional)
                structuresOptional =
                    mapFromJsObject<Structure>(game["structures"]);

            return *structuresOptional;
        }

        namespace Cpu {
            int limit() { return game["cpu"]["limit"].as<int>(); }

            int tickLimit() { return game["cpu"]["tickLimit"].as<int>(); }

            int bucket() { return game["cpu"]["bucket"].as<int>(); }
        } // namespace Cpu

        namespace Gcl {
            int level() { return game["gcl"]["level"].as<int>(); }

            int progress() { return game["gcl"]["progress"].as<int>(); }

            int progressTotal() {
                return game["gcl"]["progressTotal"].as<int>();
            }

        } // namespace Gcl

        namespace Gpl {
            int level() { return game["gpl"]["level"].as<int>(); }

            int progress() { return game["gpl"]["progress"].as<int>(); }

            int progressTotal() {
                return game["gpl"]["progressTotal"].as<int>();
            }
        } // namespace Gpl

        namespace Shard {

            std::string name() {
                return game["shard"]["name"].as<std::string>();
            }

            std::string type() {
                return game["shard"]["type"].as<std::string>();
            }

            bool ptr() { return game["shard"]["ptr"].as<bool>(); }
        } // namespace Shard

        namespace Map {
            std::unordered_map<Direction, Room::Name>
            describeExits(std::string const& roomName) {
                return {};
            }

            Find findExit(std::string const& fromRoom,
                          std::string const& toRoom) {
                return game["map"].call<Find>("findExit", fromRoom, toRoom);
            }

            std::vector<std::pair<Find, std::string>>
            findRoute(std::string const& fromRoom, std::string const& toRoom) {
                return {};
            }

            int getRoomLinearDistance(std::string const& roomName1,
                                      std::string const& roomName2,
                                      bool continuous = false) {
                return game["map"].call<int>("getRoomLinearDistance", roomName1,
                                             roomName2, continuous);
            }

            Room::Terrain getRoomTerrain(std::string const& roomName) {
                return {};
            }

            int getWorldSize() { return game["map"].call<int>("getWorldSize"); }

            bool isRoomAvailable(std::string const& roomName) {
                return game["map"].call<bool>("isRoomAvailable", roomName);
            }
        } // namespace Map

        namespace Market {
            int credits() { return game["market"]["credits"].as<int>(); }
            std::vector<Transaction> incomingTransactions() { return {}; }
            std::vector<Transaction> outgoingTransactions() { return {}; }
            std::unordered_map<std::string, Order> orders() { return {}; }
            int calcTransactionCost(int amount, Room::Name const& room1,
                                    Room::Name const& room2) {
                return game["market"].call<int>("calcTransactionCost", amount,
                                                room1, room2);
            }
            Error cancelOrder(Order::Id const& id) {
                return game["market"].call<Error>("cancelOrder", id);
            }
            Error changeOrderPrice(Order::Id const& id, int newPrice) {
                return game["market"].call<Error>("changeOrderPrice", id,
                                                  newPrice);
            }
            Error createOrder(Order::Type const& type, Resource resource,
                              int price, int totalAmount,
                              Room::Name const& room) {
                return game["market"].call<Error>("createOrder", type, resource,
                                                  price, totalAmount, room);
            }
            Error deal(Order::Id const& id, int amount,
                       Room::Name const& yourRoom) {
                return game["market"].call<Error>("deal", id, amount,
                                                  yourRoom);
            }
            Error extendOrder(Order::Id const& id, int addAmount) {
                return game["market"].call<Error>("extendOrder", id, addAmount);
            }
            Order getOrderById(Order::Id const& id) {
                return game["market"].call<Order>("getOrderById", id);
            }
        } // namespace Market

        int time() { return game["time"].as<int>(); }

        emscripten::val getObjectById(std::string const& id) {
            return game.call<emscripten::val>("getObjectById", id);
        }

        void notify(std::string const& message, unsigned int groupInterval) {
            game.call<void>("notify", message, groupInterval);
        }
    } // namespace Game
} // namespace Screeps
