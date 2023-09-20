//
// Created by michael.brunner on 18/09/2023.
//
module;

export module Playground;

import <iostream>;
import <cmath>;
import <source_location>;


export class Vector
{
public:
	Vector(double aX, double aY, double aZ)
			: x{aX}
			  , y{aY}
			  , z{aZ}
	{
	}

	Vector(const Vector& aOther)
	: x{aOther.x}
	, y{aOther.y}
	, z{aOther.z}
	{
		std::cout << "Copy Ctor " << std::source_location::current().function_name() << std::endl;
	}


	[[nodiscard]] double getX() const noexcept
	{
		return x;
	}

	[[nodiscard]] double getY() const noexcept
	{
		return y;
	}

	[[nodiscard]] double getZ() const noexcept
	{
		return z;
	}

	void setX(double aX) noexcept
	{
		x = aX;
	}

	void setY(double aY) noexcept
	{
		y = aY;
	}

	void setZ(double aZ) noexcept
	{
		z = aZ;
	}

	[[nodiscard]] double length() const noexcept
	{
		return std::sqrt(x * x + y * y + z * z);
	}

private:
	double x;
	double y;
	double z;

};

