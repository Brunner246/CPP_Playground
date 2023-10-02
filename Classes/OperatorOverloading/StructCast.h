//
// Created by michael.brunner on 29/09/2023.
//

#ifndef CPP_PLAYGROUND_STRUCTCAST_H
#define CPP_PLAYGROUND_STRUCTCAST_H

#include <iostream>

namespace Interface {
	class TestInterface
	{
	public:
		virtual ~TestInterface() = default;

		virtual void test() = 0;
	};
}

namespace Implementation {
	class TestImplementation : public Interface::TestInterface
	{
	public:
		TestImplementation() = default;

		~TestImplementation() override = default;

		void test() override
		{
			std::cout << "TestImplementation::test()" << std::endl;
		}

		void testFromImplementation()
		{
			std::cout << "TestImplementation::testFromImplementation()" << std::endl;
		}
	};
}

struct TestStruct
{
	explicit TestStruct()
	{
		mTestImplementationPtr = new Implementation::TestImplementation();
	}

	~TestStruct()
	{
		std::cout << "TestStruct::~TestStruct()" << std::endl;
		delete mTestImplementationPtr;
		mTestImplementationPtr = nullptr;
	}

	Interface::TestInterface* mTestImplementationPtr{nullptr};

	explicit operator Implementation::TestImplementation*() const {
		return dynamic_cast<Implementation::TestImplementation*>(mTestImplementationPtr);
	}
	explicit operator std::string() const
	{
		return "explicit operator std::string() const";
	}
};

namespace ConversionOperator {
	void testFunction()
	{
		auto lTestStruct = std::make_unique<TestStruct>();

		if (lTestStruct->mTestImplementationPtr) {
			std::cout << "TestStruct " << std::addressof(lTestStruct->mTestImplementationPtr) << std::endl;
			lTestStruct->mTestImplementationPtr->test();
		}
		else {
			return;
		}

		Implementation::TestImplementation* lTest = lTestStruct->operator Implementation::TestImplementation *();
		// Implementation::TestImplementation* lTest2 = dynamic_cast<Implementation::TestImplementation*>(lTestStruct.mTestImplementationPtr);
		auto lExplicitOperator = lTestStruct->operator std::string();
		// std::string lExplicitOperator2 = static_cast<std::string>(lTestStruct);
		if (lTest) {
			std::cout << "TestStruct " << std::addressof(lTest) << std::endl;
			lTest->test();
			lTest->testFromImplementation();

			lTest = nullptr;
		}
	}
}

#endif //CPP_PLAYGROUND_STRUCTCAST_H
