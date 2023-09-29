//
// Created by michael.brunner on 21/09/2023.
//

#include <vector>

template<typename T>
std::vector <T> operator<<(std::vector <T> &aVector, const T &aElement)
{
	aVector.push_back(aElement);
	return aVector;
}

std::string operator""_str(const char* aChar, std::size_t aSize)
{
	return {aChar};
}

auto operator"" _m(long double aMilliMeter)
{
	return aMilliMeter / 1000.0;
}




