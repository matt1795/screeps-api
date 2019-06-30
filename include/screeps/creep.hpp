#pragma once
namespace Screeps {
    class Creep {
      public:
        using Name = std::string;
        inline static int const lifeTime = 1500;
        inline static int const claimLifeTime = 600;
        inline static double const corpseRate = 0.2;
        inline static int const partMaxEnergy = 125;
    };
} // namespace Screeps
