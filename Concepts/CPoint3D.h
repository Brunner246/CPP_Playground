//
// Created by michael.brunner on 12/10/2023.
//

#ifndef CPP_PLAYGROUND_CPOINT3D_H
#define CPP_PLAYGROUND_CPOINT3D_H

#include <cmath>
#include <concepts>
#include <type_traits>

namespace {
	template<typename T>
	concept is_arithmetic = std::is_arithmetic_v<T>;

	template<typename T>
	concept Point = requires(T p){
		{ p.x } -> is_arithmetic;
		{ p.y } -> is_arithmetic;
		{ p.z } -> is_arithmetic;
		// alternative:
		// requires std::is_same_v<decltype(p.x), decltype(p.y)>;
		// requires std::is_same_v<decltype(p.x), decltype(p.z)>;
		// requires is_arithmetic<decltype(p.x)>;
	};
}

template<Point T>
std::floating_point auto dist(T aP1, T ap2)
{
	return std::sqrt(std::pow(aP1.x - ap2.x, 2) + std::pow(aP1.y - ap2.y, 2) + std::pow(aP1.z - ap2.z, 2));
}

template<is_arithmetic T>
class CPoint3D
{
public:
	CPoint3D(T aX, T aY, T aZ)
			: mX{aX}
			  , mY{aY}
			  , mZ{aZ}
	{
	}

	auto x() const
	{
		return mX;
	}

	auto y() const
	{
		return mY;
	}

	auto z() const
	{
		return mZ;
	}

private:
	T mX{};
	T mY{};
	T mZ{};
};

#endif //CPP_PLAYGROUND_CPOINT3D_H
