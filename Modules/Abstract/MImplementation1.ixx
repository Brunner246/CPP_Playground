//
// Created by michael.brunner on 12/10/2023.
//

export module MImplementation;

import <iostream>;

export import MInterface;


namespace Impl1 {
	export class CImplementation1 : public MInterface
	{
	public:
		~CImplementation1() noexcept override = default;

		void foo() override
		{
			std::cout << "CImplementation1::foo()" << std::endl;
		}

		void bar() override
		{
			std::cout << "CImplementation1::bar()" << std::endl;
		}

		void baz() override
		{
			std::cout << "CImplementation1::baz()" << std::endl;
		}
	};
}

namespace Impl2 {
	export class CImplementation2 : public MInterface
	{
	public:
		~CImplementation2() noexcept override = default;

		void foo() override
		{
			std::cout << "CImplementation2::foo()" << std::endl;
		}

		void bar() override
		{
			std::cout << "CImplementation2::bar()" << std::endl;
		}

		void baz() override
		{
			std::cout << "CImplementation2::baz()" << std::endl;
		}
	};
}

export enum class ImplementationType : unsigned int
{
	Impl1 = 0,
	Impl2
};

export class ImplementationFactory
{
public:
	static std::unique_ptr <MInterface> createImplementation(ImplementationType aType)
	{
		using enum ImplementationType;
		switch (aType) {
			case Impl1:
				return std::make_unique<Impl1::CImplementation1>();
			case Impl2:
				return std::make_unique<Impl2::CImplementation2>();
			default:
				return nullptr;
		}
	}
};
