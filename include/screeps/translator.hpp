// Translator Class
//
// Author: Matthew Knight
// File Name: translator.hpp
// Date: 2019-06-20

#pragma once

#include <algorithm>
#include <type_traits>

namespace Screeps {
    /**
     * This class acts as a simple bi-directional map. It does do linear search
     * in order to keep code size small so it's not meant for large datasets. On
     * the user end, you create an std::array of pairs, each entry being two
     * values that map to eachother, and construct a translator with that data.
     */
    template <typename PairArray, bool bidirectional = true>
    class Translator {
        PairArray const& data;

      public:
        constexpr Translator(PairArray const& data)
            : data(data) {}

        template <typename T>
        auto operator[](T const& value) {
            return std::find_if(
                std::begin(data), std::end(data), [&](auto& elem) {
                    if constexpr (std::is_same_v<T,
                                                 typename std::remove_extent_t<
                                                     PairArray>::first_type> ||
                                  !bidirectional) {
                        return value == elem.first;
                    } else {
                        return value == elem.second;
                    }
                });
        }

        constexpr auto begin() { return std::begin(data); }

        constexpr auto end() { return std::end(data); }
    };

    template <typename PairArray>
    class Lookup : public Translator<PairArray, false> {
      public:
        constexpr Lookup(PairArray const& data)
            : Translator<PairArray, false>(data) {}
    };
} // namespace Screeps
