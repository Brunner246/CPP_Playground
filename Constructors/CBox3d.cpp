//
// Created by michael.brunner on 17/09/2023.
//

#include <iostream>
#include <string>
#include "CBox3d.h"

namespace Constructors {
	CBox3d::CBox3d(const CBox3d &aConstructors)
			: mWidth{aConstructors.mWidth}
			  , mHeight{aConstructors.mHeight}
			  , mDepth{aConstructors.mDepth}
	{
		std::cout << "copy constructor called" << std::endl;
	}

	CBox3d &CBox3d::operator=(const CBox3d &aConstructors)
	{
		std::cout << "copy assignment called" << std::endl;
		if (this != &aConstructors) {
			auto lTemp = aConstructors;
			std::swap(mWidth, lTemp.mWidth);
			std::swap(mHeight, lTemp.mHeight);
			std::swap(mDepth, lTemp.mDepth);
		}
		return *this;
	}

	CBox3d::CBox3d(CBox3d &&aConstructors) noexcept
			: mWidth{aConstructors.mWidth}
			  , mHeight{aConstructors.mHeight}
			  , mDepth{aConstructors.mDepth}
	{
		std::cout << "move constructor called" << std::endl;

	}

	CBox3d &CBox3d::operator=(CBox3d &&aConstructors) noexcept
	{
		std::cout << "move assignment called" << std::endl;
		return *this;
	}

	CBox3d::~CBox3d()
	{
		std::cout << "destructor called" << std::endl;
	}

	CBox3d::CBox3d(const int aWidth, const int aHeight, const int aDepth)
			: mWidth{aWidth}
			  , mHeight{aHeight}
			  , mDepth{aDepth}
	{
		std::cout << "constructor called" << std::endl;
	}

	std::string CBox3d::toString() const noexcept
	{
		return std::to_string(mWidth) + " x " + std::to_string(mHeight) + " x " + std::to_string(mDepth);
	}
} // CBox3d