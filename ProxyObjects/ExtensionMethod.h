//
// Created by michael.brunner on 12/10/2023.
//

#ifndef CPP_PLAYGROUND_EXTENSIONMETHOD_H
#define CPP_PLAYGROUND_EXTENSIONMETHOD_H

#include <algorithm>


template<typename T>
struct ContainsProxy
{
	explicit ContainsProxy(const T &aValue)
			: mValue{aValue}
	{
	}
	const T &mValue;
};


template<typename Range, typename T>
auto operator|(const Range &aRange, const ContainsProxy<T> &aProxy) -> bool // decltype(aRange.begin())
{
	return std::find(aRange.begin(), aRange.end(), aProxy.mValue) != aRange.end();
}

namespace ExtensionMethod {
	template<typename Container>
	concept is_container = requires(Container aContainer)
	{
		{ aContainer.begin() } -> std::same_as<typename Container::iterator>;
		{ aContainer.end() } -> std::same_as<typename Container::iterator>;
	};

	template<is_container Container, typename T>
	bool testMethod(const Container &aContainer, T aValue)
	{
		return aContainer | ContainsProxy{aValue};
	}
}

#endif //CPP_PLAYGROUND_EXTENSIONMETHOD_H
