//
// Created by michael.brunner on 12/10/2023.
//

export module MInterface;

export class MInterface
{
public:
	virtual ~MInterface() noexcept = default;

	virtual void foo() = 0;

	virtual void bar() = 0;

	virtual void baz() = 0;
};
