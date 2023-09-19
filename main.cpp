#include <iostream>
#include "Classes/Constructors/CBox3d.h"
#include "Stack/stack.h"
#include "Classes/Constructors/CCustomArray.h"
#include "Heap/CUser.h"
#include "Library/ITestInterface.h"
#include "Library/CTestInterface.h"

import Playground;
import Playground.Test;
import Position;

auto copyElision() -> Constructors::CBox3d
{
	auto lBox = Constructors::CBox3d{1, 2, 3};
	std::cout << "copyElision(): " << std::addressof(lBox) << std::endl;
	return lBox;
}

auto copyElisionSmartPtr() -> std::unique_ptr<Constructors::CBox3d>
{
	auto lBox = std::make_unique<Constructors::CBox3d>(1, 2, 3);
	std::cout << "copyElision(): " << std::addressof(lBox) << std::endl;
	return lBox;
}


int main()
{

	//////// Stack ////////
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
	//////// Heap ////////
	std::cout << " HEAP BEGIN" << std::endl;
	std::cout << std::endl;
	{
		auto lHeap = std::make_unique<Heap::CUser>("Ctor");
		std::cout << lHeap->getName() << std::endl;
		lHeap->setDtorMessage("Ctor");
		auto lHeapCopy = std::make_unique<Heap::CUser>(*lHeap);
		lHeapCopy->setDtorMessage("Copy");
		std::cout << lHeapCopy->getName() << std::endl;
		auto lHeapMove = std::make_unique<Heap::CUser>(std::move(*lHeap));
		lHeapMove->setDtorMessage("Move");
		std::cout << lHeapMove->getName() << std::endl;
	}
	std::cout << " HEAP END" << std::endl;
	std::cout << std::endl;
	//////// Constructors ////////

	auto lBox = Constructors::CBox3d{1, 2, 3};
	{
		auto lBoxCopy = Constructors::CBox3d{lBox};
	}
	auto lBoxMove = Constructors::CBox3d{std::move(lBox)};
	auto lSomeBox = Constructors::CBox3d{4, 5, 6};
	lBox = lSomeBox;
	std::cout << lBox.toString() << std::endl;

	{
		auto lTestBox = copyElision();
		std::cout << "copyElision() check return value: " << std::addressof(lTestBox) << std::endl;
	}
	{
		auto lTestBoxSmartPtr = copyElisionSmartPtr();
		std::cout << "copyElisionSmartPtr() check return value: " << std::addressof(lTestBoxSmartPtr) << std::endl;
	}

	{
		auto lMyArray = Constructors::CCustomArray<int>{10};
		std::cout << std::addressof(lMyArray) << std::endl;
		Constructors::CCustomArray<int> lMyArray2 = std::move(lMyArray);
		std::cout << std::boolalpha;
		std::cout << std::addressof(lMyArray2) << std::endl;
		std::cout << lMyArray2.empty() << std::endl;

		for (auto il{0}; il < lMyArray2.size(); ++il) {
			lMyArray2[il] = il;
			std::cout << lMyArray2[il] << std::endl;
		}

		auto lInitailizerList = Constructors::CCustomArray<std::string>{"1", "2", "3", "4", "5"};
		for (auto il{0}; il < lInitailizerList.size(); ++il) {
			std::cout << lInitailizerList[il] << std::endl;
		}
	}

	//////// Modules ////////
	std::cout << std::endl;
	{
		Test::testFunctionModules();
		auto lVector = Vector(1.0, 2.0, 3.0);
		std::cout << "Vector length: " << lVector.length() << std::endl;
		lVector.setX(4.0);
		std::cout << "New x-coordinate: " << lVector.getX() << std::endl;

		auto lVector2 = Vector(1.0, 2.0, 4.0);
		auto lMax = std::max(CPosition(100, 100, 100), CPosition(200, 100, 101));
		std::cout << "Max: " << lMax.x << ", " << lMax.y << ", " << lMax.z << std::endl;

	}
	std::cout << std::endl;

	//////// Import Library ////////

	{
		std::unique_ptr<Library::ITestInterface> lTestInterface = std::make_unique<Library::CTestInterface>("Test");
		if (lTestInterface)
			lTestInterface->doSomething();
	}


	return EXIT_SUCCESS;
}

