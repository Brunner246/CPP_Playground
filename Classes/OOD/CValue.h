//
// Created by michael.brunner on 02/10/2023.
//

#ifndef CPP_PLAYGROUND_CVALUE_H
#define CPP_PLAYGROUND_CVALUE_H


#include <string>
#include <utility>

class CName
{
public:


private:
	std::string mLastName;
	std::string mFirstName;
};

class CAddress
{
public:
	CAddress() = default;

	CAddress(std::string aStreet, std::string aCity, std::string aZipCode, std::string aCountry)
			: mStreet(std::move(aStreet)), mCity(std::move(aCity)), mZipCode(std::move(aZipCode)), mCountry(std::move(aCountry))
	{
	}

	~CAddress() = default;

	CAddress(const CAddress& other) = default;

	CAddress(CAddress&& other) noexcept = default;

	CAddress& operator=(const CAddress& other)
	{

		if (this != &other)
		{
			mStreet = other.mStreet;
			mCity = other.mCity;
			mZipCode = other.mZipCode;
			mCountry = other.mCountry;
		}
		return *this;
	}

	CAddress& operator=(CAddress&& other) noexcept = default;

	[[nodiscard]] const std::string& getStreet() const
	{
		return mStreet;
	}

	[[nodiscard]] const std::string& getCity() const
	{
		return mCity;
	}

	[[nodiscard]] const std::string& getZipCode() const
	{
		return mZipCode;
	}

	[[nodiscard]] const std::string& getCountry() const
	{
		return mCountry;
	}

	bool operator==(const CAddress& other) const
	{
		auto lThis = std::tie(mStreet, mCity, mZipCode, mCountry);
		auto lOther = std::tie(other.mStreet, other.mCity, other.mZipCode, other.mCountry);
		return lThis == lOther;
	}

private:
	std::string mStreet;
	std::string mCity;
	std::string mZipCode;
	std::string mCountry;
};


#endif //CPP_PLAYGROUND_CVALUE_H
