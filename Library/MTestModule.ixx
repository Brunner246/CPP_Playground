//
// Created by michael.brunner on 19/09/2023.
//

module;

#include <iostream>
#include "ITestInterface.h"
#include <source_location>

export module MTestModule;


namespace Module {

	export void doSomething()
	{
		const auto &wo{std::source_location::current()};
		std::cout << wo.line() << std::endl;
		std::cout << wo.file_name() << std::endl;
		std::cout << wo.function_name() << std::endl;
	}
}
