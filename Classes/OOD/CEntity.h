//
// Created by michael.brunner on 02/10/2023.
//

#ifndef CPP_PLAYGROUND_CENTITY_H
#define CPP_PLAYGROUND_CENTITY_H


#include <string>
#include <utility>
#include <memory>
#include <unordered_map>
#include <random>
#include <iostream>


class CEntity
{
public:
	CEntity()
	{
		mId = std::random_device()();
		mRandomName = std::to_string(mId);
	};

	~CEntity() = default;

	CEntity(const CEntity &other) = default;

	CEntity(CEntity &&other) noexcept = default;

	CEntity &operator=(const CEntity &other) = default;

	CEntity &operator=(CEntity &&other) noexcept = default;

	[[nodiscard]] unsigned int getGuid() const
	{
		return mId;
	}

	[[nodiscard]] const std::string &getRandomName() const
	{
		return mRandomName;
	}

	bool operator==(const CEntity &other) const
	{
		return mId == other.mId;
	}

	bool operator!=(const CEntity &other) const
	{
		return !(*this == other);
	}

private:
	unsigned int mId;
	std::string mRandomName;

};

namespace std {
	template<>
	struct ::std::hash<CEntity>
	{
		std::hash<std::string> mHash;

		auto operator()(const CEntity &aEntity) const -> size_t
		{
			return mHash(std::to_string(aEntity.getGuid()));
		}
	};
}

auto LEntityHash = [](const CEntity &aEntity) -> size_t {
	return ::std::hash<::std::string>{}(std::to_string(aEntity.getGuid()));
};

auto lEntityCmp = [](const CEntity &aLeft, const CEntity &aRight) -> bool {
	return aLeft.getGuid() == aRight.getGuid();
};

namespace OOD
{
	bool testFunction()
	{
		auto lEntity1 = ::std::make_unique<CEntity>();
		auto lEntity2 = ::std::make_unique<CEntity>();

		std::cout << "lEntity1: " << lEntity1->getGuid() << std::endl;
		std::cout << "lEntity2: " << lEntity2->getGuid() << std::endl;

		using HashMap = ::std::unordered_map<CEntity, ::std::string, decltype(LEntityHash), decltype(lEntityCmp)>;

		HashMap lHashMap(10, LEntityHash, lEntityCmp);
		lHashMap.insert({*lEntity1, "Entity1"});
		lHashMap.insert({*lEntity2, "Entity2"});
		return lEntity1 == lEntity2;
	}

}




#endif //CPP_PLAYGROUND_CENTITY_H
