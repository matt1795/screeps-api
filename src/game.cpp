// Game Object Wrapper
//
// Author: Matthew Knight
// File Name: game.hpp
// Date: 2019-06-20

#include "screeps/game.hpp"

#include "screeps/constants.hpp"

#include <emscripten/val.h>

#include <string>
#include <unordered_map>

namespace Screeps {
    std::unordered_map<std::string, ConstructionSite>
    Game::constructionSites() {
        return {};
    }

    std::unordered_map<std::string, Creep> Game::creeps() { return {}; }

    std::unordered_map<std::string, Flag> Game::flags() { return {}; }

    std::unordered_map<std::string, PowerCreep> Game::powerCreeps() {
        return {};
    }

    std::unordered_map<std::string, Room> Game::rooms() { return {}; }

    std::unordered_map<std::string, Spawn> Game::spawns() { return {}; }

    std::unordered_map<std::string, Structure> Game::structures() { return {}; }

    int Game::Cpu::limit() { return game["cpu"]["limit"].as<int>(); }

    int Game::Cpu::tickLimit() { return game["cpu"]["tickLimit"].as<int>(); }

    int Game::Cpu::bucket() { return game["cpu"]["bucket"].as<int>(); }

    int Game::Gcl::level() { return game["gcl"]["level"].as<int>(); }

    int Game::Gcl::progress() { return game["gcl"]["progress"].as<int>(); }

    int Game::Gcl::progressTotal() {
        return game["gcl"]["progressTotal"].as<int>();
    }

    int Game::Gpl::level() { return game["gpl"]["level"].as<int>(); }

    int Game::Gpl::progress() { return game["gpl"]["progress"].as<int>(); }

    int Game::Gpl::progressTotal() {
        return game["gpl"]["progressTotal"].as<int>();
    }

    std::string Game::Shard::name() {
        return game["shard"]["name"].as<std::string>();
    }

    std::string Game::Shard::type() {
        return game["shard"]["type"].as<std::string>();
    }

    bool Game::Shard::ptr() { return game["shard"]["ptr"].as<bool>(); }

    /*
    std::unordered_map<std::string, std::string>
    Game::Map::describeExits(std::string const& roomName) {
        return {};
    }

    Find Game::Map::findExit(std::string const& fromRoom,
                             std::string const& toRoom) {}

    std::vector<std::pair<Find, std::string>>
    Game::Map::findRoute(std::string const& fromRoom,
                         std::string const& toRoom) {}

    int Game::Map::getRoomLinearDistance(std::string const& roomName1,
                                         std::string const& roomName2,
                                         bool continuous = false) {}

    Room::Terrain Game::Map::getRoomTerrain(std::string const& roomName) {}

    int Game::Map::getWorldSize() {}

    bool Game::Map::isRoomAvailable(std::string const& roomName) {}

    int Game::Market::credits();

    std::vector<Transaction> Game::Market::incomingTransactions();
    std::vector<Transaction> Game::Market::outgoingTransactions();
    std::unordered_map<std::string, Order> Game::Market::orders();
    int Game::Market::calcTransactionCost(int amount,
                                          std::string const& roomName1,
                                          std::string const& roomName2);
    Error Game::Market::cancelOrder(std::string const& orderId);
    Error Game::Market::changeOrderPrice(std::string const& orderId,
                                         int newPrice);
    Error Game::Market::createOrder(std::string const& type,
                                    std::string const& resourceType, int price,
                                    int totalAmount,
                                    std::string const& roomName);
    Error Game::Market::deal(std::string const& orderId, int amount,
                             std::string const& yourRoomName);
    Error Game::Market::extendOrder(std::string const& orderId, int addAmount);
    Order Game::Market::getOrderById(std::string const& id);
    */

    int Game::time() { return game["time"].as<int>(); }

    emscripten::val Game::getObjectById(std::string const& id) {
        return game.call<emscripten::val>("getObjectById", id);
    }

    void Game::notify(std::string const& message,
                      unsigned int groupInterval) {
        game.call<void>("notify", message, groupInterval);
    }
} // namespace Screeps
