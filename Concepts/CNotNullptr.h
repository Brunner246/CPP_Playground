//
// Created by michael.brunner on 12/10/2023.
//

#ifndef CPP_PLAYGROUND_CNOTNULLPTR_H
#define CPP_PLAYGROUND_CNOTNULLPTR_H

#include <concepts>

template <typename T>
concept is_not_nullptr = requires(T a)
{
	{ a != nullptr } -> std::same_as<bool>;
};

template <is_not_nullptr T>
class CNotNullptr
{
public:
	explicit CNotNullptr(T aPtr)
			: mPtr{aPtr}
	{
	}

	~CNotNullptr() = default;

	T get() const
	{
		return mPtr;
	}

private:
	T mPtr;

};


#endif //CPP_PLAYGROUND_CNOTNULLPTR_H
