//
// Created by michael.brunner on 17/09/2023.
//

#include <iostream>
#include <memory>
#include "CUser.h"

Heap::CUser::CUser(const std::string &aName)
		: mName{std::make_unique<std::string>(aName)}
{
	std::cout << "constructor CUser called" << std::endl;
}

Heap::CUser::CUser(const Heap::CUser &aOther)
: mName{std::make_unique<std::string>(*aOther.mName)}
{
	std::cout << "copy constructor CUser called" << std::endl;
}

Heap::CUser::CUser(Heap::CUser &&aOther) noexcept
: mName{std::move(aOther.mName)}
{
	std::cout << "move constructor CUser called" << std::endl;
}

Heap::CUser &Heap::CUser::operator=(const Heap::CUser &aOther)
{
	std::cout << "copy assignment CUser called" << std::endl;
	if (this != &aOther) {
		mName = std::make_unique<std::string>(*aOther.mName);
	}
	return *this;
}

Heap::CUser &Heap::CUser::operator=(Heap::CUser &&aOther) noexcept
{
	std::cout << "move assignment CUser called" << std::endl;
	if (this != &aOther) {
		std::swap(mName, aOther.mName);
	}
	return *this;
}

Heap::CUser::~CUser() noexcept
{
	std::cout << "destructing.. ";
	std::cout << mDtorMessage << std::endl;
	std::cout << "destructor CUser called" << std::endl;
}

std::string Heap::CUser::toString() const noexcept
{
	return *mName;
}

const std::string& Heap::CUser::getName() const noexcept
{
	return *mName;
}

void Heap::CUser::setName(const std::string &aName) noexcept
{
	mName = std::make_unique<std::string>(aName);
}

void Heap::CUser::setDtorMessage(const std::string &aMessage) noexcept
{
	mDtorMessage = aMessage;
}

