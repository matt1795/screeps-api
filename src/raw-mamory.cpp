#include "screeps/raw-memory.hpp"

namespace Screeps {
    std::string RawMemory::get() { return rawMemory.call<std::string>("get"); }

    void RawMemory::set(std::string const& value) {
        rawMemory.call<void>("set", value);
    }
}; // namespace Screeps
