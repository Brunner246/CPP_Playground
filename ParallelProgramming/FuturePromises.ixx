//
// Created by michael.brunner on 12/10/2023.
//

export module FuturePromises;

import <future>;
import <thread>;

export auto divide(const int a, const int b, std::promise<int>& aPromise)
{
	if (b == 0)
	{
		const auto lException = std::invalid_argument("Divide by zero");
		aPromise.set_exception(std::make_exception_ptr(lException));
	}
	else
	{
		const auto lResult = a / b;
		aPromise.set_value(lResult);
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
