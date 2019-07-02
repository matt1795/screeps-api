#pragma once

#include <emscripten/val.h>

#include <string>
#include <unordered_map>
#include <optional>
#include <functional>

using namespace emscripten;

namespace Screeps {
    template <typename Value>
    auto mapFromJsObject(val object) {
        std::unordered_map<std::string, Value> map;
        std::vector<std::string> keys = vecFromJSArray<std::string>(
            val::global("Object").call<val>("keys", object));

        for (auto& key : keys)
            map.emplace(std::make_pair(key, object));

        return map;
    }
} // namespace Screeps
