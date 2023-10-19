//
// Created by michael.brunner on 28/09/2023.
//

#ifndef CPP_PLAYGROUND_RULEOFFIVE_H
#define CPP_PLAYGROUND_RULEOFFIVE_H

#include <initializer_list>
#include <algorithm>

/**
 * Rule of five
 * 1. Copy constructor
 * 2. Copy assignment
 * 3. Destructor
 * 4. Move constructor
 * 5. Move assignment
 */
class Buffer
{
public:
	// Constructor
	Buffer(const std::initializer_list<float> &values)
			: size_{values.size()}
	{
		ptr_ = new float[values.size()];
		std::copy(values.begin(), values.end(), ptr_);
	}

	// 1. Copy constructor
	Buffer(const Buffer &other)
			: size_{other.size_}
	{
		ptr_ = new float[size_];
		std::copy(other.ptr_, other.ptr_ + size_, ptr_);
	}

	// 2. Copy assignment
	auto &operator=(const Buffer &other)
	{
		if (this == &other) { return *this; }
		delete[] ptr_;
		ptr_ = new float[other.size_];
		size_ = other.size_;
		std::copy(other.ptr_, other.ptr_ + size_, ptr_);
		return *this;
	}

	// 3. Destructor
	~Buffer()
	{
		delete[] ptr_;
		ptr_ = nullptr;
	}

	// 4. Move constructor
	Buffer(Buffer &&other) noexcept
			: size_{other.size_}, ptr_{other.ptr_}
	{
		other.ptr_ = nullptr;
		other.size_ = 0;
	}

	// 5. Move assignment
	auto &operator=(Buffer &&other) noexcept
	{
		ptr_ = other.ptr_;
		size_ = other.size_;
		other.ptr_ = nullptr;
		other.size_ = 0;
		return *this;
	}

	// Iterators for accessing the data
	[[nodiscard]] auto begin() const
	{
		return ptr_;
	}

	[[nodiscard]] auto end() const
	{
		return ptr_ + size_;
	}

private:
	size_t size_{0};
	float* ptr_{nullptr};
};

#endif //CPP_PLAYGROUND_RULEOFFIVE_H
