//
// Created by michael.brunner on 18/09/2023.
//
module;

#include <cmath>

export module Playground;


export class Vector
{
public:
	Vector(double aX, double aY, double aZ)
			: x{aX}
			  , y{aY}
			  , z{aZ}
	{
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

