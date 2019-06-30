#pragma once

#include <string>

namespace Screeps {
    struct Order {
        using Id = std::string;
        enum class Type {
            Buy,
            Sell
        };
    };
}
