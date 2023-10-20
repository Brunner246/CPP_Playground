#include <iostream>
#include "Classes/Constructors/CBox3d.h"
#include "Stack/StackMain.h"
#include "Classes/Constructors/CCustomArray.h"
#include "Heap/CUser.h"
#include "Library/ITestInterface.h"
#include "Library/CTestInterface.h"
#include "Classes/OperatorOverloading/FreeOperator.h"
#include "Classes/OperatorOverloading/StructCast.h"
#include "Classes/OOD/CEntity.h"
#include "Concepts/CDividable.h"
#include <cpr/cpr.h>
#include <string>
#include <algorithm>
#include "Concepts/CPoint3D.h"
#include "Concepts/CNotNullptr.h"
#include "ProxyObjects/ExtensionMethod.h"
#include "ProxyObjects/CWriteReadLazy.h"
#include "Classes/OOD/Strategy/StrategyMain.h"
#include <cassert>

import Playground;
import Playground.Test;
import Position;
import CVec3D;
import MImplementation;
import MInterface;
import MAccount;
import FuturePromises;
import SRP;
import OCP;
import Observer;

#if PARALLEL

#include <execution>

#define PAR std::execution::par,
#else
#define SEQ
#define PAR
#endif


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

struct Beam
{
	[[nodiscard]] auto reflect_beam() const
	{
		return L"Beam";
	}
};

struct Panel
{
	[[nodiscard]] auto reflect_panel() const
	{
		return L"Panel";
	}
};


template<typename Component>
auto reflect(const Component &aComponent)
{
	if constexpr (std::is_same_v<Component, Beam>) {
		return aComponent.reflect_beam();
	}
	if constexpr (std::is_same_v<Component, Panel>) {
		return aComponent.reflect_panel();
	} else {
		return L"Unknown";
	}
}

/////////////////////// FUNCTION TEMPLATE function ///////////////////////
auto function(auto x) -> decltype(x) { return x; }

/**
 * @brief Concept for arithmetic types
 * @tparam T
 */
template <typename T>
concept IsNumber = std::is_arithmetic_v<T>
		|| std::is_floating_point_v<T>;

/**
 * @brief Function template with concept
 * @tparam T
 * @return T
 */
template<IsNumber T>
std::function<T(T,T)> f = [](T a, T b) -> T { return a + b; };

/////////////////////// FUNCTION TEMPLATE f ///////////////////////

void pointerArgs(std::string** aString)
{
	if (aString == nullptr
	|| *aString == nullptr)
	{
		throw std::invalid_argument("aString is nullptr");
	}
	**aString = "Hello World";
}

void promises(std::string const& aString, std::promise<std::string>& aPromise)
{
	if (aString.empty())
	{
		const auto lException = std::invalid_argument("aString is empty");
		aPromise.set_exception(std::make_exception_ptr(lException));
	}
	else
	{
		using namespace std::string_literals;
		auto lResult = aString + " World"s;
		aPromise.set_value(lResult);
	}
}

int main()
{

	cpr::Response r = cpr::Get(cpr::Url{"https://jsonplaceholder.typicode.com/users"},
	                           cpr::Authentication{"user", "pass", cpr::AuthMode::BASIC},
	                           cpr::Parameters{{"", ""},
	                                           {"", ""}});
	r.status_code;                  // 200
	r.header["content-type"];       // application/json; charset=utf-8
	auto lResponse = r.text;                       // JSON text string
	std::cout << lResponse << std::endl;

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

		std::weak_ptr<Constructors::CBox3d> lWeakPtr;
		{
			lWeakPtr = std::weak_ptr<Constructors::CBox3d>(lSharedPtrBox);
			std::cout << "weak pointer count " << lWeakPtr.use_count() << std::endl;
		}
		lWeakPtr.reset();
		std::cout << "weak pointer count " << lWeakPtr.use_count() << std::endl;
		if (lWeakPtr.expired()) {
			std::cout << "    weak pointer expired" << std::endl;
		}
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
//		auto lMax = std::ranges::max(CPosition(100, 100, 100), CPosition(200, 100, 101));
//		std::cout << "Max: " << lMax.x << ", " << lMax.y << ", " << lMax.z << std::endl;

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

	std::vector<int> lIntVector;
	lIntVector << 1;
	lIntVector << 2;
	lIntVector << 3;
	lIntVector << 4;

	{
		std::list<int> lIntList(1000);
		std::ranges::iota(lIntList, 0);
		auto lResult = std::reduce(PAR lIntList.begin(), lIntList.end(), 0, [](auto aLeft, auto aRight) {
			return aLeft + aRight;
		});
		std::cout << "Result: " << lResult << std::endl;
	}

	auto lString = "Hello World"_str;
	std::cout << lString << std::endl;

	auto lBeam = Beam{};
	auto lPanel = Panel{};

	std::wcout << reflect(lBeam) << std::endl;

	std::wcout << reflect(lPanel) << std::endl;

	std::cout << 1'500.0_m << " m" << std::endl;

	ConversionOperator::testFunction();

	if (!OOD::testFunction()) {
		std::cout << "entities not equal" << std::endl;
	}

	{
		auto lDividable = CDividable<int>();
		lDividable.divide(1, 2);
	}

	double lDouble = 123.456;
	int lInt1 = (int) lDouble;
	int lInt2 = static_cast<int>(lDouble);
	int lInt3 = static_cast<int>(std::floor(lDouble));
	int lInt4 = static_cast<int>(std::ceil(lDouble));
	{
		auto lPoint3D = CPoint3D<double>{1.0, 2.0, 3.0};
		lPoint3D.x();
	}

	{
		auto vec1 = Geometry::CVec3D{1, 2, 3};
		auto vec2 = Geometry::CVec3D{4, 5, 6};

		if (vec1.length() < vec2.length()) {
			std::cout << "vec1 is shorter than vec2" << std::endl;
			double lLength1 = vec1.length();
			double lLength2 = vec2.length();
			std::cout << "vec1 length: " << lLength1 << std::endl;
			std::cout << "vec2 length: " << lLength2 << std::endl;
		}
		if (vec1.length() > 1e-6) {
			std::cout << "vec1 is not zero" << std::endl;
		}
	}

	{
		auto lMyClass = ImplementationFactory::createImplementation(ImplementationType::Impl1);
		lMyClass->foo();
		lMyClass->baz();


		std::shared_ptr<MInterface> lMyClass2 = std::make_shared<Impl2::CImplementation2>();
		lMyClass2->baz();

		CNotNullptr lNotNull = CNotNullptr<decltype(lMyClass2)>(lMyClass2);
		auto lGet = lNotNull.get();
	}

	{
		using namespace std::string_literals;
		std::vector<std::string> lVec{"foo"s, "bar"s, "baz"s};
		auto lResult = ExtensionMethod::testMethod(lVec, "bar"s);
		if (lResult) {
			std::cout << "Found" << std::endl;
		} else {
			std::cout << "Not found" << std::endl;
		}

		auto lIntResult = ExtensionMethod::testMethod(lIntVector, 3);
		if (lIntResult) {
			std::cout << "Found" << std::endl;
		} else {
			std::cout << "Not found" << std::endl;
		}
	}

	{
		auto lAccount1 = BankAccount::CAccount(1'000);
		auto lAccount2 = BankAccount::CAccount(2'000);

		std::cout << "Account 1: " << lAccount1.getBalance() << std::endl;
		std::cout << "Account 2: " << lAccount2.getBalance() << std::endl;

		BankAccount::transferMoney(lAccount1, lAccount2, 500);

		std::cout << "Account 1: " << lAccount1.getBalance() << std::endl;
		std::cout << "Account 2: " << lAccount2.getBalance() << std::endl;

	}
	{
		/////////////// Future and Promises ///////////////
		std::promise<int> lPromise;
		int lQuotient = 10;
		int lDividend = 0;
		std::jthread lThread{divide, lQuotient, lDividend, std::ref(lPromise)};
		auto lFuture = lPromise.get_future(); // get_future() must be called before the thread starts
		std::cout << "Waiting for result..." << std::endl;
		try {
			auto lResult = lFuture.get(); // get() blocks until the result is available
			std::cout << "Result: " << lResult << std::endl;
			assert((lQuotient / lDividend) == lResult);
		} catch (const std::invalid_argument &e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}

	}
	{
		writeFile();
		auto lReader = CWriteReadLazy(R"(C:\Users\michael.brunner\CLionProjects\CPP-Playground\ProxyObjects\fstream.dat)");
		auto lStream = lReader.read();

		std::cout << lStream.str() << std::endl;

	}

	{
		Strategy::strategyMain();
	}
	{
		auto lDocument = SOLID::JsonDocument();
		std::cout << lDocument.toJson();
		std::cout << std::endl;
		SOLID::testFunction();

		auto lJournal = SOLID::Journal("My Journal");
		lJournal.add_entries("I ate a bug");
		lJournal.add_entries("I cried today");

		auto lFileName = "./journal.txt";
		SOLID::SavingManager::save(lJournal, lFileName);
	}
	{
		function(1);
		std::future<int> lResult = std::async(std::launch::async, f<int>, 1, 2);
		if (lResult.valid()) {
			std::cout << "Result: " << lResult.get() << std::endl;
		}
		auto lResult2 = f<double>(1.123, 2.345);
		std::cout << "Result: " << lResult2 << std::endl;
	}
	{
		std::string* lPtr = nullptr;
		std::string** lPtrPtr = &lPtr;
		std::string lMyString = "Test";

		try
		{
			pointerArgs(lPtrPtr);
			std::cout << *lPtr << std::endl;
		}
		catch (std::invalid_argument& e)
		{
			std::cout << e.what() << std::endl;
		}

		{
			OBSERVER::observerMain();
		}

	}

	return EXIT_SUCCESS;
}

