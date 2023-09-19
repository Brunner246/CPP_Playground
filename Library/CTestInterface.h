//
// Created by michael.brunner on 19/09/2023.
//

#ifndef LIBRARY_CTESTINTERFACE_H
#define LIBRARY_CTESTINTERFACE_H

#include "ITestInterface.h"

namespace Library {

	class CTestInterface : public ITestInterface
	{
	public:
		explicit CTestInterface(std::string&& aName);
		~CTestInterface() override = default;

		void doSomething() override;

	private:
		std::string mName;
	};

} // Library

#endif //LIBRARY_CTESTINTERFACE_H
