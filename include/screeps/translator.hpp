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
    template <typename PairArray, bool bidirectional = true> class Translator { PairArray const& data;

      public:
        constexpr Translator(PairArray const& data)
            : data(data) {}

        template <typename T>
        typename PairArray::const_iterator operator[](T const& value) {
            return std::find_if(data.cbegin(), data.cend(), [&](auto& elem) {
                if constexpr (std::is_same_v<
                                  T,
                                  typename PairArray::value_type::first_type> || !bidirectional) {
                    return value == elem.first;
                } else {
                    return value == elem.second;
                }
            });
        }
    };

	template <typename PairArray>
	using Lookup<PairArray> = Translator<PairArray, false>;

} // namespace Screeps
