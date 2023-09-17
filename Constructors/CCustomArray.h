//
// Created by michael.brunner on 17/09/2023.
//

#ifndef CPP_PLAYGROUND_CCUSTOMARRAY_H
#define CPP_PLAYGROUND_CCUSTOMARRAY_H

#include <memory>
#include <iostream>

namespace Constructors {

	template<typename T>
	class CCustomArray final
	{
	public:
		CCustomArray() = delete;

		explicit CCustomArray(const int aSize)
				: mArray{std::make_unique<T[]>(aSize)}, mSize(aSize)
		{
			std::cout << "constructor called" << std::endl;
		}

		CCustomArray(std::initializer_list<T> aList)
				: mArray{std::make_unique<T[]>(aList.size())}, mSize(aList.size())
		{
			std::cout << "initializer_list constructor called" << std::endl;
			auto i{0};
			for (auto &lElement : aList) {
				mArray[i++] = lElement;
			}
		}

		CCustomArray(const CCustomArray &aOther)
				: mArray{std::make_unique<T[]>(aOther.mSize)}, mSize(aOther.mSize)
		{
			std::cout << "copy constructor called" << std::endl;
			std::copy(aOther.mArray.get(), aOther.mArray.get() + mSize, mArray.get());
		}

		CCustomArray(CCustomArray &&aOther) noexcept
				: mArray{std::move(aOther.mArray)}, mSize(aOther.mSize)
		{
			std::cout << "move constructor called" << std::endl;
		}

		CCustomArray &operator=(const CCustomArray &aOther)
		{
			std::cout << "copy assignment called" << std::endl;
			if (this != &aOther) {
				mArray = std::make_unique<T[]>(aOther.mSize);
				mSize = aOther.mSize;
				std::copy(aOther.mArray.get(), aOther.mArray.get() + mSize, mArray.get());
			}
			return *this;
		}

		CCustomArray &operator=(CCustomArray &&aOther) noexcept
		{
			std::cout << "move assignment called" << std::endl;
			if (this != &aOther) {
				mArray = std::move(aOther.mArray);
				mSize = aOther.mSize;
			}
			return *this;
		}

		~CCustomArray() noexcept
		{
			std::cout << "destructor called" << std::endl;
		};

		[[nodiscard]] bool empty() const
		{
			return mSize == 0;
		}

		T &operator[](const int aIndex)
		{
			if (aIndex < 0 || aIndex >= mSize) {
				throw std::out_of_range("Index out of range");
			}
			return mArray[aIndex];
		}

		const T &operator[](const int aIndex) const
		{
			if (aIndex < 0 || aIndex >= mSize) {
				throw std::out_of_range("Index out of range");
			}
			return mArray[aIndex];
		}

		[[nodiscard]] int size() const
		{
			return mSize;
		}

	private:
		std::unique_ptr<T[]> mArray;
		int mSize;
	};


} // Constructors

#endif //CPP_PLAYGROUND_CCUSTOMARRAY_H
