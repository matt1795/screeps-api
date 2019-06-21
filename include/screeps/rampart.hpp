namespace Screeps {
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
}
