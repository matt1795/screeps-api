// Screeps Constants File
//
// Author: Matthew Knight
// File Name: constants.hpp
// Date: 2019-06-20

#pragma once

#include "screeps/enums.hpp"
#include "screeps/structure.hpp"
#include "screeps/translator.hpp"

#include <array>
#include <set>
#include <tuple>

namespace Screeps {
    namespace {
        std::pair<Look, char const*> const lookData[] = {
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
            std::make_pair(Look::PowerCreeps, "powerCreep")};

        std::pair<BodyPart, char const*> const bodyPartData[] = {
            std::make_pair(BodyPart::Move, "move"),
            std::make_pair(BodyPart::Work, "work"),
            std::make_pair(BodyPart::Carry, "carry"),
            std::make_pair(BodyPart::Attack, "attack"),
            std::make_pair(BodyPart::RangedAttack, "ranged_attack"),
            std::make_pair(BodyPart::Tough, "tough"),
            std::make_pair(BodyPart::Heal, "heal"),
            std::make_pair(BodyPart::Claim, "claim")};

        std::pair<BodyPart, int> const bodyPartCostData[] = {
            std::make_pair(BodyPart::Move, 50),
            std::make_pair(BodyPart::Work, 100),
            std::make_pair(BodyPart::Carry, 50),
            std::make_pair(BodyPart::Attack, 80),
            std::make_pair(BodyPart::RangedAttack, 150),
            std::make_pair(BodyPart::Tough, 10),
            std::make_pair(BodyPart::Heal, 250),
            std::make_pair(BodyPart::Claim, 600)};

        std::pair<StructureType, char const*> const structureData[] = {
            std::make_pair(StructureType::Spawn, "spawn"),
            std::make_pair(StructureType::Extension, "extension"),
            std::make_pair(StructureType::Road, "road"),
            std::make_pair(StructureType::Wall, "constructedWall"),
            std::make_pair(StructureType::Rampart, "rampart"),
            std::make_pair(StructureType::KeeperLair, "keeperLair"),
            std::make_pair(StructureType::Portal, "portal"),
            std::make_pair(StructureType::Controller, "controller"),
            std::make_pair(StructureType::Link, "link"),
            std::make_pair(StructureType::Storage, "storage"),
            std::make_pair(StructureType::Tower, "tower"),
            std::make_pair(StructureType::Observer, "observer"),
            std::make_pair(StructureType::PowerBank, "powerBank"),
            std::make_pair(StructureType::PowerSpawn, "powerSpawn"),
            std::make_pair(StructureType::Extractor, "extractor"),
            std::make_pair(StructureType::Lab, "lab"),
            std::make_pair(StructureType::Terminal, "terminal"),
            std::make_pair(StructureType::Container, "container"),
            std::make_pair(StructureType::Nuker, "nuker")};

        std::pair<StructureType, int> const structureCostData[] = {
            std::make_pair(StructureType::Spawn, 15000),
            std::make_pair(StructureType::Extension, 3000),
            std::make_pair(StructureType::Road, 300),
            std::make_pair(StructureType::Wall, 1),
            std::make_pair(StructureType::Rampart, 1),
            std::make_pair(StructureType::Link, 5000),
            std::make_pair(StructureType::Storage, 30000),
            std::make_pair(StructureType::Tower, 5000),
            std::make_pair(StructureType::Observer, 8000),
            std::make_pair(StructureType::PowerSpawn, 100000),
            std::make_pair(StructureType::Extractor, 5000),
            std::make_pair(StructureType::Lab, 50000),
            std::make_pair(StructureType::Terminal, 100000),
            std::make_pair(StructureType::Container, 5000),
            std::make_pair(StructureType::Nuker, 100000)};

        std::pair<Resource, char const*> const resourceData[] = {
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
            std::make_pair(Resource::LemergiumAcid, "LH2O"),
            std::make_pair(Resource::LemergiumAlkalide, "LHO2"),
            std::make_pair(Resource::ZynthiumAcid, "ZH2O"),
            std::make_pair(Resource::ZynthiumAlkalide, "ZHO2"),
            std::make_pair(Resource::GhodiumAcid, "GH2O"),
            std::make_pair(Resource::GhodiumAlkalide, "GHO2"),
            std::make_pair(Resource::CatalyzedUtriumAcid, "XUH2O"),
            std::make_pair(Resource::CatalyzedUtriumAlkalide, "XUHO2"),
            std::make_pair(Resource::CatalyzedKeaniumAcid, "XKH2O"),
            std::make_pair(Resource::CatalyzedKeaniumAlkalide, "XKHO2"),
            std::make_pair(Resource::CatalyzedLemergiumAcid, "XLH2O"),
            std::make_pair(Resource::CatalyzedLemergiumAlkalide, "XLHO2"),
            std::make_pair(Resource::CatalyzedZynthiumAcid, "XZH2O"),
            std::make_pair(Resource::CatalyzedZynthiumAlkalide, "XZHO2"),
            std::make_pair(Resource::CatalyzedGhodiumAcid, "XGH2O"),
            std::make_pair(Resource::CatalyzedGhodiumAlkalide, "XGHO2")};
    } // namespace

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
    float const repairCost = 0.01;
    float const dismantleCost = 0.005;

    int const maxConstructionSites = 100;
    int const maxCreepSize = 50;
    int const flagLimit = 10000;
    char const* subscriptionToken = "token";

    std::set<char const*> const obstacleObjectTypes = {
        "spawn",           "creep",     "powerCreep",
        "source",          "mineral",   "controller",
        "constructedWall", "extension", "link",
        "storage",         "tower",     "observer",
        "powerSpawn",      "powerBank", "lab",
        "terminal",        "nuker"};

    namespace EnergyInfo {
        int const regenTime = 300;
        int const decay = 1000;
    } // namespace EnergyInfo

    namespace ConstructionCost {
        int const roadSwampRatio = 5;
        int const roadWallRatio = 150;
    } // namespace ConstructionCost

    namespace SafeModeInfo {
        int const duration = 20000;
        int const cooldown = 50000;
        int const cost = 1000;
    } // namespace SafeModeInfo

    namespace GclInfo {
        float const pow = 2.4;
        int const multiply = 1000000;
        int const novice = 3;
    } // namespace GclInfo
} // namespace Screeps
