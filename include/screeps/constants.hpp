// Screeps Constants File
//
// Author: Matthew Knight
// File Name: constants.hpp
// Date: 2019-06-20

#pragma once

namespace Screeps {
/**
 * This file contains a typed version of screeps constants
 */
    enum class Error {
        Ok = 0,
        NotOwner = -1,
        NoPath = -2,
        Name_exists = -3,
        Busy = -4,
        NotFound = -5,
        NotEnoughEnergy = -6,
        NotEnoughResources = -6,
        InvalidTarget = -7,
        Full = -8,
        NotInRange = -9,
        InvalidArgs = -10,
        Tired = -11,
        NoBodypart = -12,
        NotEnoughExtensions = -6,
        RclNotEnough = -14,
        GclNotEnough = -15,
    };

    enum class Find {
        ExitTop = 1,
        ExitRight = 3,
        ExitBottom = 5,
        ExitLeft = 7,
        Exit = 10,
        Creeps = 101,
        MyCreeps = 102,
        HostileCreeps = 103,
        SourcesActive = 104,
        Sources = 105,
        DroppedEnergy = -106,
        DroppedResources = 106,
        Structures = 107,
        MyStructures = 108,
        HostileStructures = 109,
        Flags = 110,
        ConstructionSites = 111,
        MySpawns = 112,
        HostileSpawns = 113,
        MyConstructionSites = 114,
        HostileConstructionSites = 115,
        Minerals = 116,
        Nukes = 117,
        Tombstones = 118,
        PowerCreeps = 119,
        MyPowerCreeps = 120,
        HostilePowerCreeps = 121,
    };

    enum class Position {
        Top = 1,
        TopRight = 2,
        Right = 3,
        BottomRight = 4,
        Bottom = 5,
        BottomLeft = 6,
        Left = 7,
        TopLeft = 8,
    };

    enum class Color {
        Red = 1,
        Purple = 2,
        Blue = 3,
        Cyan = 4,
        Green = 5,
        Yellow = 6,
        Orange = 7,
        Brown = 8,
        Grey = 9,
        White = 10,
    };

    LOOK_CREEPS: "creep",
    LOOK_ENERGY: "energy",
    LOOK_RESOURCES: "resource",
    LOOK_SOURCES: "source",
    LOOK_MINERALS: "mineral",
    LOOK_STRUCTURES: "structure",
    LOOK_FLAGS: "flag",
    LOOK_CONSTRUCTION_SITES: "constructionSite",
    LOOK_NUKES: "nuke",
    LOOK_TERRAIN: "terrain",
    LOOK_TOMBSTONES: "tombstone",
    LOOK_POWER_CREEPS: "powerCreep",

    OBSTACLE_OBJECT_TYPES: ["spawn", "creep", "powerCreep", "source", "mineral", "controller", "constructedWall", "extension", "link", "storage", "tower", "observer", "powerSpawn", "powerBank", "lab", "terminal","nuker"],

    std::set<std::string> obstacleObjectTypes const = {
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

    enum class BodyPart {
        Move
        Work
        Carry
        Attack
        RangedAttack
        Tough
        Heal
        Claim
    };

    std::map<BodyPart, std::string> const bodyPartMap = {
        { BodyPart::Move, "move" },
        { BodyPart::Work, "work" },
        { BodyPart::Carry, "carry" },
        { BodyPart::Attack, "attack" },
        { BodyPart::RangedAttack, "ranged_attack" },
        { BodyPart::Tough, "tough" },
        { BodyPart::Heal, "heal" },
        { BodyPart::Claim, "claim" },
    }

    std::map<BodyPart, int> bodyPartCost const = {
        { BodyPart::Move, 50 },
        { BodyPart::Work, 100 },
        { BodyPart::Carry, 50 },
        { BodyPart::Attack, 80 },
        { BodyPart::RangedAttack, 150 },
        { BodyPart::Tough, 10 },
        { BodyPart::Heal, 250 },
        { BodyPart::Claim, 600 }
    };

    int const worldWidth = 202;
    int const worldHeight = 202;

    class Creep {
        inline static int const lifeTime: 1500,
        inline static int const claimLifeTime: 600,
        inline static double const corpseRate: 0.2,
        inline static int const partMaxEnergy: 125,
    };

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

    class Rampart {
        inline static int const decayAmount = 300;
        inline static int const decayTime = 100;
        inline static int const hits = 1;
        inline static std::map<int, int> hitsMax const = {
            { 2, 300000 },
            { 3, 1000000 },
            { 4, 3000000 },
            { 5, 10000000 },
            { 6, 30000000 },
            { 7, 100000000 },
            { 8, 300000000 }
        };
    }

    namespace EnergyInfo {
        int const regenTime = 300;
        int const decay = 1000;
    }

    class Spawn {
        inline static int const hits = 5000;
        inline static int const energyStart = 300;
        inline static int const energyCapacity = 300;
        inline static int const spawnTime = 3;
        inline static double const renewRatio = 1.2;
    };

    class EnergySource {
        SOURCE_ENERGY_CAPACITY: 3000,
        SOURCE_ENERGY_NEUTRAL_CAPACITY: 1500,
        SOURCE_ENERGY_KEEPER_CAPACITY: 4000,
    };

    class Wall {
        WALL_HITS: 1,
        WALL_HITS_MAX: 300000000,
    };

    class Extension {
        EXTENSION_HITS: 1000,
        EXTENSION_ENERGY_CAPACITY: {0: 50, 1: 50, 2: 50, 3: 50, 4: 50, 5: 50, 6: 50, 7: 100, 8: 200},
    };

    class Road {
        ROAD_HITS: 5000,
        ROAD_WEAROUT: 1,
        ROAD_WEAROUT_POWER_CREEP: 100,
        ROAD_DECAY_AMOUNT: 100,
        ROAD_DECAY_TIME: 1000,
    };

    class Link {
        LINK_HITS: 1000,
        LINK_HITS_MAX: 1000,
        LINK_CAPACITY: 800,
        LINK_COOLDOWN: 1,
        LINK_LOSS_RATIO: 0.03,
    };

    class Storage {
        STORAGE_CAPACITY: 1000000,
        STORAGE_HITS: 10000,
    };

    enum class Structure {
        Spawn,
        Extension,
        Road,
        Wall,
        Rampart,
        KeeperLair,
        Portal,
        Controller,
        Link,
        Storage,
        Tower,
        Observer,
        PowerBank,
        PowerSpawn,
        Extractor,
        Lab,
        Terminal,
        Container,
        Nuker
    };

    STRUCTURE_SPAWN: "spawn",
    STRUCTURE_EXTENSION: "extension",
    STRUCTURE_ROAD: "road",
    STRUCTURE_WALL: "constructedWall",
    STRUCTURE_RAMPART: "rampart",
    STRUCTURE_KEEPER_LAIR: "keeperLair",
    STRUCTURE_PORTAL: "portal",
    STRUCTURE_CONTROLLER: "controller",
    STRUCTURE_LINK: "link",
    STRUCTURE_STORAGE: "storage",
    STRUCTURE_TOWER: "tower",
    STRUCTURE_OBSERVER: "observer",
    STRUCTURE_POWER_BANK: "powerBank",
    STRUCTURE_POWER_SPAWN: "powerSpawn",
    STRUCTURE_EXTRACTOR: "extractor",
    STRUCTURE_LAB: "lab",
    STRUCTURE_TERMINAL: "terminal",
    STRUCTURE_CONTAINER: "container",
    STRUCTURE_NUKER: "nuker",

    CONSTRUCTION_COST: {
        "spawn": 15000,
        "extension": 3000,
        "road": 300,
        "constructedWall": 1,
        "rampart": 1,
        "link": 5000,
        "storage": 30000,
        "tower": 5000,
        "observer": 8000,
        "powerSpawn": 100000,
        "extractor": 5000,
        "lab": 50000,
        "terminal": 100000,
        "container": 5000,
        "nuker": 100000
    },
    CONSTRUCTION_COST_ROAD_SWAMP_RATIO: 5,
    CONSTRUCTION_COST_ROAD_WALL_RATIO: 150,

    class Controller {
        levels: {1: 200, 2: 45000, 3: 135000, 4: 405000, 5: 1215000, 6: 3645000, 7: 10935000},
        structures: {
            "spawn": {0: 0, 1: 1, 2: 1, 3: 1, 4: 1, 5: 1, 6: 1, 7: 2, 8: 3},
            "extension": {0: 0, 1: 0, 2: 5, 3: 10, 4: 20, 5: 30, 6: 40, 7: 50, 8: 60},
            "link": {1: 0, 2: 0, 3: 0, 4: 0, 5: 2, 6: 3, 7: 4, 8: 6},
            "road": {0: 2500, 1: 2500, 2: 2500, 3: 2500, 4: 2500, 5: 2500, 6: 2500, 7: 2500, 8: 2500},
            "constructedwall": {1: 0, 2: 2500, 3: 2500, 4: 2500, 5: 2500, 6: 2500, 7: 2500, 8: 2500},
            "rampart": {1: 0, 2: 2500, 3: 2500, 4: 2500, 5: 2500, 6: 2500, 7: 2500, 8: 2500},
            "storage": {1: 0, 2: 0, 3: 0, 4: 1, 5: 1, 6: 1, 7: 1, 8: 1},
            "tower": {1: 0, 2: 0, 3: 1, 4: 1, 5: 2, 6: 2, 7: 3, 8: 6},
            "observer": {1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0, 7: 0, 8: 1},
            "powerspawn": {1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0, 7: 0, 8: 1},
            "extractor": {1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 1, 7: 1, 8: 1},
            "terminal": {1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 1, 7: 1, 8: 1},
            "lab": {1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 3, 7: 6, 8: 10},
            "container": {0: 5, 1: 5, 2: 5, 3: 5, 4: 5, 5: 5, 6: 5, 7: 5, 8: 5},
            "nuker": {1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0, 7: 0, 8: 1}
        },
        downgrade: {1: 20000, 2: 10000, 3: 20000, 4: 40000, 5: 80000, 6: 120000, 7: 150000, 8: 200000},
        downgradeRestore: 100,
        downgradeSafemodeThreshold: 5000,
        claimDowngrade: 300,
        reserve: 1,
        reserveMax: 5000,
        maxUpgradePerTick: 15,
        attackBlockedUpgrade: 1000,
        nukeBlockedUpgrade: 200,
    };

    namespace SafeModeInfo {
        SAFE_MODE_DURATION: 20000,
        SAFE_MODE_COOLDOWN: 50000,
        SAFE_MODE_COST: 1000,
    }

    class Tower {
        TOWER_HITS: 3000,
        TOWER_CAPACITY: 1000,
        TOWER_ENERGY_COST: 10,
        TOWER_POWER_ATTACK: 600,
        TOWER_POWER_HEAL: 400,
        TOWER_POWER_REPAIR: 800,
        TOWER_OPTIMAL_RANGE: 5,
        TOWER_FALLOFF_RANGE: 20,
        TOWER_FALLOFF: 0.75,
    };

    class Observer {
        OBSERVER_HITS: 500,
        OBSERVER_RANGE: 10,
    };

    class PowerBank {
        POWER_BANK_HITS: 2000000,
        POWER_BANK_CAPACITY_MAX: 5000,
        POWER_BANK_CAPACITY_MIN: 500,
        POWER_BANK_CAPACITY_CRIT: 0.3,
        POWER_BANK_DECAY: 5000,
        POWER_BANK_HIT_BACK: 0.5,
    };

    class PowerSpawn {
        POWER_SPAWN_HITS: 5000,
        POWER_SPAWN_ENERGY_CAPACITY: 5000,
        POWER_SPAWN_POWER_CAPACITY: 100,
        POWER_SPAWN_ENERGY_RATIO: 50,
    };

    class Extractor {
        EXTRACTOR_HITS: 500,
        EXTRACTOR_COOLDOWN: 5,
    };

    class Lab {
        LAB_HITS: 500,
        LAB_MINERAL_CAPACITY: 3000,
        LAB_ENERGY_CAPACITY: 2000,
        LAB_BOOST_ENERGY: 20,
        LAB_BOOST_MINERAL: 30,
        LAB_COOLDOWN: 10,           // not used
        LAB_REACTION_AMOUNT: 5,
        LAB_UNBOOST_ENERGY: 0,
        LAB_UNBOOST_MINERAL: 15,
    };

    GCL_POW: 2.4,
    GCL_MULTIPLY: 1000000,
    GCL_NOVICE: 3,

    TERRAIN_MASK_WALL: 1,
    TERRAIN_MASK_SWAMP: 2,
    TERRAIN_MASK_LAVA: 4,

    MAX_CONSTRUCTION_SITES: 100,
    MAX_CREEP_SIZE: 50,

    MINERAL_REGEN_TIME: 50000,
    MINERAL_MIN_AMOUNT: {
        "H": 35000,
        "O": 35000,
        "L": 35000,
        "K": 35000,
        "Z": 35000,
        "U": 35000,
        "X": 35000
    },
    MINERAL_RANDOM_FACTOR: 2,

    MINERAL_DENSITY: {
        1: 15000,
        2: 35000,
        3: 70000,
        4: 100000
    },
    MINERAL_DENSITY_PROBABILITY  : {
        1: 0.1,
        2: 0.5,
        3: 0.9,
        4: 1.0
    },
    MINERAL_DENSITY_CHANGE: 0.05,

    DENSITY_LOW: 1,
    DENSITY_MODERATE: 2,
    DENSITY_HIGH: 3,
    DENSITY_ULTRA: 4,

    class Terminal {
        TERMINAL_CAPACITY: 300000,
        TERMINAL_HITS: 3000,
        TERMINAL_SEND_COST: 0.1,
        TERMINAL_MIN_SEND: 100,
        TERMINAL_COOLDOWN: 10,
    };

    class Container {
        CONTAINER_HITS: 250000,
        CONTAINER_CAPACITY: 2000,
        CONTAINER_DECAY: 5000,
        CONTAINER_DECAY_TIME: 100,
        CONTAINER_DECAY_TIME_OWNED: 500,
    };

    class Nuker {
        NUKER_HITS: 1000,
        NUKER_COOLDOWN: 100000,
        NUKER_ENERGY_CAPACITY: 300000,
        NUKER_GHODIUM_CAPACITY: 5000,
        NUKE_LAND_TIME: 50000,
        NUKE_RANGE: 10,
        NUKE_DAMAGE: {
            0: 10000000,
            2: 5000000
        },
    };

    class Tombstone {
        TOMBSTONE_DECAY_PER_PART: 5,
        TOMBSTONE_DECAY_POWER_CREEP: 500,
    };

    class Portal {
        PORTAL_DECAY: 30000,
    };

    class Order {
        ORDER_SELL: "sell",
        ORDER_BUY: "buy",
    };

    class Market {
        MARKET_FEE: 0.05,
    };

    FLAGS_LIMIT: 10000,

    SUBSCRIPTION_TOKEN: "token",

    RESOURCE_ENERGY: "energy",
    RESOURCE_POWER: "power",

    RESOURCE_HYDROGEN: "H",
    RESOURCE_OXYGEN: "O",
    RESOURCE_UTRIUM: "U",
    RESOURCE_LEMERGIUM: "L",
    RESOURCE_KEANIUM: "K",
    RESOURCE_ZYNTHIUM: "Z",
    RESOURCE_CATALYST: "X",
    RESOURCE_GHODIUM: "G",

    RESOURCE_HYDROXIDE: "OH",
    RESOURCE_ZYNTHIUM_KEANITE: "ZK",
    RESOURCE_UTRIUM_LEMERGITE: "UL",

    RESOURCE_UTRIUM_HYDRIDE: "UH",
    RESOURCE_UTRIUM_OXIDE: "UO",
    RESOURCE_KEANIUM_HYDRIDE: "KH",
    RESOURCE_KEANIUM_OXIDE: "KO",
    RESOURCE_LEMERGIUM_HYDRIDE: "LH",
    RESOURCE_LEMERGIUM_OXIDE: "LO",
    RESOURCE_ZYNTHIUM_HYDRIDE: "ZH",
    RESOURCE_ZYNTHIUM_OXIDE: "ZO",
    RESOURCE_GHODIUM_HYDRIDE: "GH",
    RESOURCE_GHODIUM_OXIDE: "GO",

    RESOURCE_UTRIUM_ACID: "UH2O",
    RESOURCE_UTRIUM_ALKALIDE: "UHO2",
    RESOURCE_KEANIUM_ACID: "KH2O",
    RESOURCE_KEANIUM_ALKALIDE: "KHO2",
    RESOURCE_LEMERGIUM_ACID: "LH2O",
    RESOURCE_LEMERGIUM_ALKALIDE: "LHO2",
    RESOURCE_ZYNTHIUM_ACID: "ZH2O",
    RESOURCE_ZYNTHIUM_ALKALIDE: "ZHO2",
    RESOURCE_GHODIUM_ACID: "GH2O",
    RESOURCE_GHODIUM_ALKALIDE: "GHO2",

    RESOURCE_CATALYZED_UTRIUM_ACID: "XUH2O",
    RESOURCE_CATALYZED_UTRIUM_ALKALIDE: "XUHO2",
    RESOURCE_CATALYZED_KEANIUM_ACID: "XKH2O",
    RESOURCE_CATALYZED_KEANIUM_ALKALIDE: "XKHO2",
    RESOURCE_CATALYZED_LEMERGIUM_ACID: "XLH2O",
    RESOURCE_CATALYZED_LEMERGIUM_ALKALIDE: "XLHO2",
    RESOURCE_CATALYZED_ZYNTHIUM_ACID: "XZH2O",
    RESOURCE_CATALYZED_ZYNTHIUM_ALKALIDE: "XZHO2",
    RESOURCE_CATALYZED_GHODIUM_ACID: "XGH2O",
    RESOURCE_CATALYZED_GHODIUM_ALKALIDE: "XGHO2",

    RESOURCE_OPS: "ops",

    REACTIONS: {
        H: {
            O: "OH",
            L: "LH",
            K: "KH",
            U: "UH",
            Z: "ZH",
            G: "GH"
        },
        O: {
            H: "OH",
            L: "LO",
            K: "KO",
            U: "UO",
            Z: "ZO",
            G: "GO"
        },
        Z: {
            K: "ZK",
            H: "ZH",
            O: "ZO"
        },
        L: {
            U: "UL",
            H: "LH",
            O: "LO"
        },
        K: {
            Z: "ZK",
            H: "KH",
            O: "KO"
        },
        G: {
            H: "GH",
            O: "GO"
        },
        U: {
            L: "UL",
            H: "UH",
            O: "UO"
        },
        OH: {
            UH: "UH2O",
            UO: "UHO2",
            ZH: "ZH2O",
            ZO: "ZHO2",
            KH: "KH2O",
            KO: "KHO2",
            LH: "LH2O",
            LO: "LHO2",
            GH: "GH2O",
            GO: "GHO2"
        },
        X: {
            UH2O: "XUH2O",
            UHO2: "XUHO2",
            LH2O: "XLH2O",
            LHO2: "XLHO2",
            KH2O: "XKH2O",
            KHO2: "XKHO2",
            ZH2O: "XZH2O",
            ZHO2: "XZHO2",
            GH2O: "XGH2O",
            GHO2: "XGHO2"
        },
        ZK: {
            UL: "G"
        },
        UL: {
            ZK: "G"
        },
        LH: {
            OH: "LH2O"
        },
        ZH: {
            OH: "ZH2O"
        },
        GH: {
            OH: "GH2O"
        },
        KH: {
            OH: "KH2O"
        },
        UH: {
            OH: "UH2O"
        },
        LO: {
            OH: "LHO2"
        },
        ZO: {
            OH: "ZHO2"
        },
        KO: {
            OH: "KHO2"
        },
        UO: {
            OH: "UHO2"
        },
        GO: {
            OH: "GHO2"
        },
        LH2O: {
            X: "XLH2O"
        },
        KH2O: {
            X: "XKH2O"
        },
        ZH2O: {
            X: "XZH2O"
        },
        UH2O: {
            X: "XUH2O"
        },
        GH2O: {
            X: "XGH2O"
        },
        LHO2: {
            X: "XLHO2"
        },
        UHO2: {
            X: "XUHO2"
        },
        KHO2: {
            X: "XKHO2"
        },
        ZHO2: {
            X: "XZHO2"
        },
        GHO2: {
            X: "XGHO2"
        }
    },

    BOOSTS: {
        work: {
            UO: {
                harvest: 3
            },
            UHO2: {
                harvest: 5
            },
            XUHO2: {
                harvest: 7
            },
            LH: {
                build: 1.5,
                repair: 1.5
            },
            LH2O: {
                build: 1.8,
                repair: 1.8
            },
            XLH2O: {
                build: 2,
                repair: 2
            },
            ZH: {
                dismantle: 2
            },
            ZH2O: {
                dismantle: 3
            },
            XZH2O: {
                dismantle: 4
            },
            GH: {
                upgradeController: 1.5
            },
            GH2O: {
                upgradeController: 1.8
            },
            XGH2O: {
                upgradeController: 2
            }
        },
        attack: {
            UH: {
                attack: 2
            },
            UH2O: {
                attack: 3
            },
            XUH2O: {
                attack: 4
            }
        },
        ranged_attack: {
            KO: {
                rangedAttack: 2,
                rangedMassAttack: 2
            },
            KHO2: {
                rangedAttack: 3,
                rangedMassAttack: 3
            },
            XKHO2: {
                rangedAttack: 4,
                rangedMassAttack: 4
            }
        },
        heal: {
            LO: {
                heal: 2,
                rangedHeal: 2
            },
            LHO2: {
                heal: 3,
                rangedHeal: 3
            },
            XLHO2: {
                heal: 4,
                rangedHeal: 4
            }
        },
        carry: {
            KH: {
                capacity: 2
            },
            KH2O: {
                capacity: 3
            },
            XKH2O: {
                capacity: 4
            }
        },
        move: {
            ZO: {
                fatigue: 2
            },
            ZHO2: {
                fatigue: 3
            },
            XZHO2: {
                fatigue: 4
            }
        },
        tough: {
            GO: {
                damage: .7
            },
            GHO2: {
                damage: .5
            },
            XGHO2: {
                damage: .3
            }
        }
    },

    REACTION_TIME: {
        OH: 20,
        ZK: 5,
        UL: 5,
        G: 5,
        UH: 10,
        UH2O: 5,
        XUH2O: 60,
        UO: 10,
        UHO2: 5,
        XUHO2: 60,
        KH: 10,
        KH2O: 5,
        XKH2O: 60,
        KO: 10,
        KHO2: 5,
        XKHO2: 60,
        LH: 15,
        LH2O: 10,
        XLH2O: 65,
        LO: 10,
        LHO2: 5,
        XLHO2: 60,
        ZH: 20,
        ZH2O: 40,
        XZH2O: 160,
        ZO: 10,
        ZHO2: 5,
        XZHO2: 60,
        GH: 10,
        GH2O: 15,
        XGH2O: 80,
        GO: 10,
        GHO2: 30,
        XGHO2: 150,
    },

    PORTAL_UNSTABLE: 10*24*3600*1000,
    PORTAL_MIN_TIMEOUT: 12*24*3600*1000,
    PORTAL_MAX_TIMEOUT: 22*24*3600*1000,

    POWER_BANK_RESPAWN_TIME: 50000,

    INVADERS_ENERGY_GOAL: 100000,

    SYSTEM_USERNAME: 'Screeps',

    // SIGN_NOVICE_AREA and SIGN_RESPAWN_AREA constants are deprecated, please use SIGN_PLANNED_AREA instead
    SIGN_NOVICE_AREA: 'A new Novice or Respawn Area is being planned somewhere in this sector. Please make sure all important rooms are reserved.',
    SIGN_RESPAWN_AREA: 'A new Novice or Respawn Area is being planned somewhere in this sector. Please make sure all important rooms are reserved.',
    SIGN_PLANNED_AREA: 'A new Novice or Respawn Area is being planned somewhere in this sector. Please make sure all important rooms are reserved.',

    EVENT_ATTACK: 1,
    EVENT_OBJECT_DESTROYED: 2,
    EVENT_ATTACK_CONTROLLER: 3,
    EVENT_BUILD: 4,
    EVENT_HARVEST: 5,
    EVENT_HEAL: 6,
    EVENT_REPAIR: 7,
    EVENT_RESERVE_CONTROLLER: 8,
    EVENT_UPGRADE_CONTROLLER: 9,
    EVENT_EXIT: 10,
    EVENT_POWER: 11,
    EVENT_TRANSFER: 12,

    EVENT_ATTACK_TYPE_MELEE: 1,
    EVENT_ATTACK_TYPE_RANGED: 2,
    EVENT_ATTACK_TYPE_RANGED_MASS: 3,
    EVENT_ATTACK_TYPE_DISMANTLE: 4,
    EVENT_ATTACK_TYPE_HIT_BACK: 5,
    EVENT_ATTACK_TYPE_NUKE: 6,

    EVENT_HEAL_TYPE_MELEE: 1,
    EVENT_HEAL_TYPE_RANGED: 2,

    POWER_LEVEL_MULTIPLY: 1000,
    POWER_LEVEL_POW: 2,
    POWER_CREEP_SPAWN_COOLDOWN: 8*3600*1000,
    POWER_CREEP_DELETE_COOLDOWN: 24*3600*1000,
    POWER_CREEP_MAX_LEVEL: 25,
    POWER_CREEP_LIFE_TIME: 5000,

    POWER_CLASS: {
        OPERATOR: 'operator'
    },

    PWR_GENERATE_OPS: 1,
    PWR_OPERATE_SPAWN: 2,
    PWR_OPERATE_TOWER: 3,
    PWR_OPERATE_STORAGE: 4,
    PWR_OPERATE_LAB: 5,
    PWR_OPERATE_EXTENSION: 6,
    PWR_OPERATE_OBSERVER: 7,
    PWR_OPERATE_TERMINAL: 8,
    PWR_DISRUPT_SPAWN: 9,
    PWR_DISRUPT_TOWER: 10,
    PWR_DISRUPT_SOURCE: 11,
    PWR_SHIELD: 12,
    PWR_REGEN_SOURCE: 13,
    PWR_REGEN_MINERAL: 14,
    PWR_DISRUPT_TERMINAL: 15,
    PWR_OPERATE_POWER: 16,
    PWR_FORTIFY: 17,
    PWR_OPERATE_CONTROLLER: 18,
    PWR_OPERATE_FACTORY: 19
});
