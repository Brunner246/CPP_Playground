//
// Created by michael.brunner on 19/09/2023.
//

#include "StackMain.h"
#include "stack.h"
#include <iostream>

void stackMain()
{
	std::cout << "////////////// Stack //////////////" << std::endl;
	auto i{0};
	std::cout << "main(): " << std::addressof(i) << std::endl;
	std::cout << std::endl;

	Stack::function2();
	std::cout << std::endl;

	Stack::function1();
	std::cout << std::endl;

	Stack::function3(i);
	std::cout << std::endl;

	Stack::function3(&i);
	std::cout << std::endl;

	{
		const int lRet = Stack::function4(i);
		std::cout << "Return value of function4(i): " << std::addressof(lRet) << std::endl;
	}
	std::cout << std::endl;
	{
		decltype(auto) lRet = Stack::function4Ref(i);
		std::cout << "Return value of function4Ref(i): " << std::addressof(lRet) << std::endl;
	}
	std::cout << std::endl;
	{
		auto lRet = Stack::function5(&i);
		std::cout << "Return value of function5(&i): " << std::addressof(lRet) << std::endl;
	}
	std::cout << std::endl;
	{
		auto lRet = Stack::function6();
		std::cout << "Return value of function6(): " << std::addressof(lRet) << std::endl;
	}
	std::cout << "////////////// Stack //////////////" << std::endl;
	std::cout << std::endl;
}
