//
// Created by michael.brunner on 19/09/2023.
//

#include <iostream>
#include <source_location>
#include "CTestInterface.h"

import MTestModule;

namespace Library {

	void CTestInterface::doSomething()
	{
		std::cout << "mName: " << mName << std::endl;
		Module::doSomething();
	}

	CTestInterface::CTestInterface(std::string &&aName)
		: mName{std::move(aName)}
	{
		std::cout << "CTestInterface::CTestInterface(" << mName << ")" << std::endl;
	}
} // Library