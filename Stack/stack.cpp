//
// Created by michael.brunner on 17/09/2023.
//

#include <iostream>
#include "stack.h"

/**************************************************************
                           STACK
**************************************************************/

void Stack::function1() noexcept
{
	auto i{0};
	std::cout << "function1(): " << std::addressof(i) << std::endl;
}

void Stack::function2() noexcept
{
	auto i{0};
	std::cout << "function2(): " << std::addressof(i) << std::endl;
	function1();
}

void Stack::function3(int aInt) noexcept
{
	std::cout << "function3(int aInt): " << std::addressof(aInt) << std::endl;
}

void Stack::function3(int* aInt) noexcept
{
	std::cout << "function3(int* aInt): " << std::addressof(aInt) << std::endl;
}

int Stack::function4(int aInt) noexcept
{
	std::cout << "function4(int aInt): " << std::addressof(aInt) << std::endl;
	return aInt;
}

const int* Stack::function5(const int* aInt) noexcept
{
	std::cout << "function5(int* aInt): " << std::addressof(aInt) << std::endl;
	return aInt;
}

const int &Stack::function4Ref(const int &aInt) noexcept
{
	std::cout << "function4Ref(int& aInt): " << std::addressof(aInt) << std::endl;
	return aInt;
}

int Stack::function6() noexcept
{
	auto i{100};
	std::cout << "function6(): " << std::addressof(i) << std::endl;
	return i;
}
