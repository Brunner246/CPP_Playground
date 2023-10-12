//
// Created by michael.brunner on 12/10/2023.
//

module;

export module CVec3D;

import <compare>;
import <cmath>;
import <iostream>;


namespace PrivateProxy {
	class CLengthProxy
	{
	public:
		CLengthProxy(const double aX, const double aY, const double aZ)
				: mSquaredLength{std::pow(aX, 2) + std::pow(aY, 2) + std::pow(aZ, 2)}
		{
		}

		bool operator==(const CLengthProxy &aOther) const = default;
		auto operator<=>(const CLengthProxy &aOther) const = default;

		friend auto operator<=>(const CLengthProxy &aOther, double aLength)
		{
			std::cout << "friend operator<=> called" << std::endl;
			return aOther.mSquaredLength <=> aLength * aLength;
		}

		operator double() const && noexcept // && forces rvalue reference
		{ // allow implicit cast to double
			std::cout << "Implicit cast to double called" << std::endl;
			return std::sqrt(mSquaredLength);
		}

	private:
		double mSquaredLength{};
	};
}


export namespace Geometry {
	class CVec3D
	{
	public:
		CVec3D(double aX, double aY, double aZ)
				: mX{aX}
				  , mY{aY}
				  , mZ{aZ}
		{
		}

		CVec3D(const CVec3D &aOther)
		: mX{aOther.mX}
		  , mY{aOther.mY}
		  , mZ{aOther.mZ}
		{
			std::cout << "CVec3D copy constructor called" << std::endl;
		}

		[[nodiscard]] auto length() const
		{
			return PrivateProxy::CLengthProxy(mX, mY, mZ);
		}

	private:
		double mX{};
		double mY{};
		double mZ{};

	};
}
