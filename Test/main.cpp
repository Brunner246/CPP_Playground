//
// Created by michael.brunner on 19/09/2023.
//


#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest/doctest.h"
#include "../Library/CTestInterface.h"

int fact(int n)
{
	return n <= 1 ? n : fact(n - 1) * n;
}

int add(int a, int b)
{
	return a + b;
}

std::unique_ptr <Library::ITestInterface> createTestClass()
{
	return std::make_unique<Library::CTestInterface>("Default");
}

// @formatter:off


TEST_CASE("testing the factorial function")
	{
	REQUIRE_FALSE(fact(1) == 0);
	CHECK(fact(2)== 2);
	CHECK(fact(3)== 6);
	CHECK(fact(10)== 3628800);
	}

TEST_CASE("testing the createTestClass function")
	{
	auto testClass = createTestClass();
	CHECK(testClass != nullptr);
	}


TEST_CASE("Testing addition") {
DOCTEST_CHECK(add(2, 3) == 5);

DOCTEST_CHECK(add(5, -3) == 2);

DOCTEST_CHECK(add(-2, -3) == -5);

}

TEST_CASE("vectors can be sized and resized") {
	std::vector<int> v(5);

	REQUIRE(v.size() == 5);
	REQUIRE(v.capacity() >= 5);

	SUBCASE("adding to the vector increases its size") {
	v.push_back(1);

	CHECK(v.size() == 6);
	CHECK(v.capacity() >= 6);
	}
	SUBCASE("reserving increases just the capacity") {
	v.reserve(6);

	CHECK(v.size() == 5);
	CHECK(v.capacity() >= 6);
	}
}


// @formatter:on