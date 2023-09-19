//
// Created by michael.brunner on 19/09/2023.
//

module;

#include <cmath>

export module Position;

export struct CPosition
{
	int x;
	int y;
	int z;

	[[nodiscard]] double length() const
	{
		return std::sqrt(x * x + y * y + z * z);
	}

	bool operator<(const CPosition& aOther) const
	{
		return this->length() < aOther.length();
	}

	bool operator>(const CPosition& aOther) const
	{
		return this->length() > aOther.length();
	}
};