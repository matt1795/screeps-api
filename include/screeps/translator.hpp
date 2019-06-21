#include <unordered_map>
#include <string>

std::array data = {
	std::make_pair(1, "one"),
	std::make_pair(2, "two")
};

template <typename PairArray>
class Translator {
	PairArray const& data;
	public:
	constexpr Translator(PairArray const& data) : data(data) {}

	template <template T>
	PairArray::const_iterator operator[](T const& val) {
		auto it = std::find_if(data.cbegin(), data.cend(), [](auto& elem) {
				if constexpr (std::is_same_v<T, PairArray::T::first_value>) {
					return val == elem.first;
				} else {
					return val == elem.second;
				}
				});
	}
};
