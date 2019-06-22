#pragma once

#include <emscripten/val.h>

#include <string>

namespace Screeps {
    // TODO: All the other methods
    class RawMemory {
        inline static emscripten::val rawMemory =
            emscripten::val::global("RawMemory");

      public:
        static std::string get() { return rawMemory.call<std::string>("get"); }

        static void set(std::string const& value) {
            rawMemory.call<void>("set", value);
        }
    };
} // namespace Screeps
