// Screeps Constants File
//
// Author: Matthew Knight
// File Name: constants.hpp
// Date: 2019-06-20

#pragma once

#include <array>

namespace Screeps {
    namespace {
        std::array const lookData = {
            std::make_pair(Look::Creeps, "creep"),
            std::make_pair(Look::Energy, "energy"),
            std::make_pair(Look::Resources, "resource"),
            std::make_pair(Look::Sources, "source"),
            std::make_pair(Look::Minerals, "mineral"),
            std::make_pair(Look::Structures, "structure"),
            std::make_pair(Look::Flags, "flag"),
            std::make_pair(Look::ConstructionSites, "constructionSite"),
            std::make_pair(Look::Nukes, "nuke"),
            std::make_pair(Look::Terrain, "terrain"),
            std::make_pair(Look::Tombstones, "tombstone"),
            std::make_pair(Look::PowerCreeps, "powerCreep"),
        };

        std::array const bodyPartData = {
            std::make_pair(BodyPart::Move, "move"),
            std::make_pair(BodyPart::Work, "work"),
            std::make_pair(BodyPart::Carry, "carry"),
            std::make_pair(BodyPart::Attack, "attack"),
            std::make_pair(BodyPart::RangedAttack, "ranged_attack"),
            std::make_pair(BodyPart::Tough, "tough"),
            std::make_pair(BodyPart::Heal, "heal"),
            std::make_pair(BodyPart::Claim, "claim"),
        };

        std::array const bodyPartCostData = {
            std::make_pair(BodyPart::Move, 50),
            std::make_pair(BodyPart::Work, 100),
            std::make_pair(BodyPart::Carry, 50),
            std::make_pair(BodyPart::Attack, 80),
            std::make_pair(BodyPart::RangedAttack, 150),
            std::make_pair(BodyPart::Tough, 10),
            std::make_pair(BodyPart::Heal, 250),
            std::make_pair(BodyPart::Claim, 600)
        };

        std::array const structureData = {
            std::make_pair(Structure::Spawn, "spawn"),
            std::make_pair(Structure::Extension, "extension"),
            std::make_pair(Structure::Road, "road"),
            std::make_pair(Structure::Wall, "constructedWall"),
            std::make_pair(Structure::Rampart, "rampart"),
            std::make_pair(Structure::KeeperLair, "keeperLair"),
            std::make_pair(Structure::Portal, "portal"),
            std::make_pair(Structure::Controller, "controller"),
            std::make_pair(Structure::Link, "link"),
            std::make_pair(Structure::Storage, "storage"),
            std::make_pair(Structure::Tower, "tower"),
            std::make_pair(Structure::Observer, "observer"),
            std::make_pair(Structure::PowerBank, "powerBank"),
            std::make_pair(Structure::PowerSpawn, "powerSpawn"),
            std::make_pair(Structure::Extractor, "extractor"),
            std::make_pair(Structure::Lab, "lab"),
            std::make_pair(Structure::Terminal, "terminal"),
            std::make_pair(Structure::Container, "container"),
            std::make_pair(Structure::Nuker, "nuker"),
        };

        std::array const structureCostData = {
            std::make_pair(Structure::Spawn, 15000),
            std::make_pair(Structure::Extension, 3000),
            std::make_pair(Structure::Road, 300),
            std::make_pair(Structure::ConstructedWall, 1),
            std::make_pair(Structure::Rampart, 1),
            std::make_pair(Structure::Link, 5000),
            std::make_pair(Structure::Storage, 30000),
            std::make_pair(Structure::Tower, 5000),
            std::make_pair(Structure::Observer, 8000),
            std::make_pair(Structure::PowerSpawn, 100000),
            std::make_pair(Structure::Extractor, 5000),
            std::make_pair(Structure::Lab, 50000),
            std::make_pair(Structure::Terminal, 100000),
            std::make_pair(Structure::Container, 5000),
            std::make_pair(Structure::Nuker, 100000),
        };

        std::array const resourceData = {
            std::make_pair(Resource::Energy, "energy"),
            std::make_pair(Resource::Power, "power"),
            std::make_pair(Resource::Ops, "ops"),
            std::make_pair(Resource::Hydrogen, "H"),
            std::make_pair(Resource::Oxygen, "O"),
            std::make_pair(Resource::Utrium, "U"),
            std::make_pair(Resource::Lemergium, "L"),
            std::make_pair(Resource::Keanium, "K"),
            std::make_pair(Resource::Zynthium, "Z"),
            std::make_pair(Resource::Catalyst, "X"),
            std::make_pair(Resource::Ghodium, "G"),
            std::make_pair(Resource::Hydroxide, "OH"),
            std::make_pair(Resource::ZynthiumKeanite, "ZK"),
            std::make_pair(Resource::UtriumLemergite, "UL"),
            std::make_pair(Resource::UtriumHydride, "UH"),
            std::make_pair(Resource::UtriumOxide, "UO"),
            std::make_pair(Resource::KeaniumHydride, "KH"),
            std::make_pair(Resource::KeaniumOxide, "KO"),
            std::make_pair(Resource::LemergiumHydride, "LH"),
            std::make_pair(Resource::LemergiumOxide, "LO"),
            std::make_pair(Resource::ZynthiumHydride, "ZH"),
            std::make_pair(Resource::ZynthiumOxide, "ZO"),
            std::make_pair(Resource::GhodiumHydride, "GH"),
            std::make_pair(Resource::GhodiumOxide, "GO"),
            std::make_pair(Resource::UtriumAcid, "UH2O"),
            std::make_pair(Resource::UtriumAlkalide, "UHO2"),
            std::make_pair(Resource::KeaniumAcid, "KH2O"),
            std::make_pair(Resource::KeaniumAlkalide, "KHO2"),
            std::make_pair(Resource::LEMERGIUM_ACID, "LH2O"),
            std::make_pair(Resource::LEMERGIUM_ALKALIDE, "LHO2"),
            std::make_pair(Resource::ZYNTHIUM_ACID, "ZH2O"),
            std::make_pair(Resource::ZYNTHIUM_ALKALIDE, "ZHO2"),
            std::make_pair(Resource::GHODIUM_ACID, "GH2O"),
            std::make_pair(Resource::GHODIUM_ALKALIDE, "GHO2"),
            std::make_pair(Resource::CATALYZED_UTRIUM_ACID, "XUH2O"),
            std::make_pair(Resource::CATALYZED_UTRIUM_ALKALIDE, "XUHO2"),
            std::make_pair(Resource::CATALYZED_KEANIUM_ACID, "XKH2O"),
            std::make_pair(Resource::CATALYZED_KEANIUM_ALKALIDE, "XKHO2"),
            std::make_pair(Resource::CATALYZED_LEMERGIUM_ACID, "XLH2O"),
            std::make_pair(Resource::CATALYZED_LEMERGIUM_ALKALIDE, "XLHO2"),
            std::make_pair(Resource::CATALYZED_ZYNTHIUM_ACID, "XZH2O"),
            std::make_pair(Resource::CATALYZED_ZYNTHIUM_ALKALIDE, "XZHO2"),
            std::make_pair(Resource::CATALYZED_GHODIUM_ACID, "XGH2O"),
            std::make_pair(Resource::CATALYZED_GHODIUM_ALKALIDE, "XGHO2"),
        };
    }

    Translator lookTranslator(lookData);
    Translator bodyPartTranslator(bodyPartData);
    Translator structureTranslator(structureData);
    Translator resourceTranslator(resourceData);

	Lookup bodyPartCostLookup(bodyPartCostData);
	Lookup structureCostLookup(structureCostData);

    int const worldWidth = 202;
    int const worldHeight = 202;
    int const carryCapacity = 50;
    int const harvestPower = 2;
    int const harvestMineralPower = 1;
    int const repairPower = 100;
    int const dismantlePower = 50;
    int const buildPower = 5;
    int const attackPower = 30;
    int const upgradeControllerPower = 1;
    int const rangedAttackPower = 10;
    int const healPower = 12;
    int const rangedHealPower = 4;
    double const repairCost = 0.01;
    int const dismantleCost = 0.005;

    int const maxConstructionSites = 100;
    int const maxCreepSize = 50;
    int const flagLimit = 10000;
    char* const subscriptionToken = "token";

    std::set<char* const> const obstacleObjectTypes = {
        "spawn",
        "creep",
        "powerCreep",
        "source",
        "mineral",
        "controller",
        "constructedWall",
        "extension",
        "link",
        "storage",
        "tower",
        "observer",
        "powerSpawn",
        "powerBank",
        "lab",
        "terminal",
        "nuker"
    };

    namespace EnergyInfo {
        int const regenTime = 300;
        int const decay = 1000;
    }

    namespace ConstructionCost {
        int const roadSwampRatio = 5;
        int const roadWallRatio = 150;
    }

    namespace SafeModeInfo {
        int const duration = 20000;
        int const cooldown = 50000;
        int const cost = 1000;
    }

    namespace GclInfo {
        float const pow = 2.4;
        int const multiply = 1000000;
        int const novice = 3;
    }
}
