//
// Created by michael.brunner on 05/10/2023.
//

#ifndef CPP_PLAYGROUND_CDIVIDABLE_H
#define CPP_PLAYGROUND_CDIVIDABLE_H

#include <concepts>

template<typename T>
concept dividable = requires(T a, T b)
{
	{ a / b } -> std::same_as<T>;
};

template <dividable T>
class CDividable
{
public:
	CDividable() = default;
	~CDividable() = default;

	T divide(T a, T b)
	{
		return a / b;
	}


private:

};


#endif //CPP_PLAYGROUND_CDIVIDABLE_H
