#pragma once

#include "screeps/controller.hpp"
#include "screeps/mineral.hpp"
#include "screeps/room-object.hpp"
#include "screeps/source.hpp"
#include "screeps/tombstone.hpp"

#include <map>

namespace Screeps {
    class Creep : public RoomObject {
      public:
        using Name = std::string;

        inline static int const lifeTime = 1500;
        inline static int const claimLifeTime = 600;
        inline static double const corpseRate = 0.2;
        inline static int const partMaxEnergy = 125;

        Creep(emscripten::val object);

        // readable attributes
        std::vector<BodyPart> body() const;
        std::map<Resource, int> carry() const;
        int carryCapacity() const;
        int fatigue() const;
        int hits() const;
        int hitsMax() const;
        Id id() const;
        // TODO: memory?
        bool my() const;
        Name name() const;
        std::string owner() const;
        std::string saying() const;
        bool spawning() const;
        int ticksToLive() const;

        // methods
        Error attack(Creep const& creep);
        Error attack(Structure const& structure);
        Error attackController(Structure const& structure);
        Error build(ConstructionSite const& constructionSite);
        Error cancelOrder(std::string const& methodName);
        Error claimController(Controller const& controller);
        Error dismantle(Structure const& structure);
        Error drop(Resource resource);
        Error drop(Resource resource, int amount);
        Error generateSafeMode(Controller const& controller);
        int getActiveBodyParts(BodyPart part);
        Error harvest(Source const& source);
        Error harvest(Mineral const& mineral);
        Error heal(Creep const& creep);
        Error move(Direction direction);
        Error moveByPath(Path const& path);
        // TODO: moveTo -- options
        Error moveTo(int x, int y);
        Error moveTo(RoomPosition const& roomPosition);
        Error notifyWhenAttacked(bool enabled);
        Error pickup(Resource resource);
        Error pull(Creep const& creep);
        Error rangedAttack(Creep const& creep);
        Error rangedAttack(Structure const& structure);
        Error rangedHeal(Creep const& creep);
        Error rangedMassAttack();
        Error repair(Structure const& structure);
        Error reserveController(Controller const& controller);
        Error say(std::string const& message, bool pub = false);
        Error signController(Controller const& controller,
                             std::string const& text);
        Error suicide();
        Error transfer(Creep const& creep, Resource resource);
        Error transfer(Creep const& creep, Resource resource, int amount);
        Error transfer(Structure const& structure, Resource resource);
        Error transfer(Structure const& structure, Resource resource,
                       int amount);
        Error upgradeController(Controller const& controller);
        Error withdraw(Structure const& structure, Resource resource);
        Error withdraw(Tombstone const& tombstone, Resource resource);
    };
} // namespace Screeps
