//
// Created by michael.brunner on 29/09/2023.
//

#ifndef CPP_PLAYGROUND_WRAPDELETE_H
#define CPP_PLAYGROUND_WRAPDELETE_H

#include <iostream>

namespace Test {
	class ITest
	{
	public:
		virtual ~ITest() = default;

		virtual void destroy() = 0;
	};

	class CTest : public ITest
	{
	public:
		CTest() = default;

		~CTest() override = default;

		void destroy() override
		{
			delete this;
		}
	};

	void testFunction()
	{
		Test::ITest* lTestPtr = new Test::CTest();
		if (lTestPtr)
		{
			lTestPtr->destroy();
			lTestPtr = nullptr;
		}
		if (lTestPtr == nullptr)
			std::cout << "lTestPtr is nullptr" << std::endl;
	}
}

#endif //CPP_PLAYGROUND_WRAPDELETE_H
