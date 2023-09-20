#include <iostream>
#include "Classes/Constructors/CBox3d.h"
#include "Stack/StackMain.h"
#include "Classes/Constructors/CCustomArray.h"
#include "Heap/CUser.h"
#include "Library/ITestInterface.h"
#include "Library/CTestInterface.h"

import Playground;
import Playground.Test;
import Position;
#include <algorithm>

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

auto callCopyConstructor(auto aValue)
{
	auto lValue = aValue;
	return lValue;
}

std::shared_ptr<Constructors::CBox3d> callCopyConstructor(std::shared_ptr<Constructors::CBox3d> aBox)
{
	std::cout << "pointer count method begin " << aBox.use_count() << std::endl;
	auto lValue = aBox;
	std::cout << "pointer count method operator= " << aBox.use_count() << std::endl;
	return lValue;
}


int main()
{

	//////// Stack ////////
	stackMain();

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
		std::cout << std::endl;
		std::cout << "SHARED POINTER" << std::endl;

		auto lSharedPtrBox = std::make_shared<Constructors::CBox3d>(1, 1, 1);
		std::cout << "pointer first initalization " << lSharedPtrBox.use_count() << std::endl;

		auto lSharedPtrBoxCopy = lSharedPtrBox;
		std::cout << "pointer count operator= " << lSharedPtrBox.use_count() << std::endl;
		std::shared_ptr<Constructors::CBox3d> lTest = callCopyConstructor(lSharedPtrBoxCopy);
		std::cout << "pointer count method return value (back in main) " << lSharedPtrBox.use_count() << std::endl;
		lTest->toString();
		std::cout << "SHARED POINTER" << std::endl;
		std::cout << std::endl;
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

		auto lVector2 = Vector(lVector);
		auto lMax = std::max(CPosition(100, 100, 100), CPosition(200, 100, 101));
		std::cout << "Max: " << lMax.x << ", " << lMax.y << ", " << lMax.z << std::endl;

		const auto &[lMinPt, lMaxPt] = std::ranges::minmax(CPosition(100, 100, 100), CPosition(200, 100, 101),
		                                                   [](const auto &aLeft, const auto &aRight) {
			                                                   return aLeft.z < aRight.z;
		                                                   });

		std::cout << "Min: " << lMinPt.x << ", " << lMinPt.y << ", " << lMinPt.z << std::endl;
		std::cout << "Max: " << lMaxPt.x << ", " << lMaxPt.y << ", " << lMaxPt.z << std::endl;

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

