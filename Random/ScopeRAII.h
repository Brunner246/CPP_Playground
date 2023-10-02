//
// Created by michael.brunner on 30/09/2023.
//

#ifndef CPP_PLAYGROUND_SCOPERAII_H
#define CPP_PLAYGROUND_SCOPERAII_H

#include <functional>

namespace ScopeRAII {
	class CScopeRAII final
	{
	public:
		explicit CScopeRAII(std::function<void()> aFunction)
				: mFunction(std::move(aFunction))
		{
		}

		~CScopeRAII()
		{
			mFunction();
		}

	private:
		std::function<void()> mFunction;
	};

	void exampleCode()
	{
		auto lInt = new int{42};
		CScopeRAII lScopeRAII{[&lInt]() {
			delete lInt;
			lInt = nullptr;
		}};
	}
}

#endif //CPP_PLAYGROUND_SCOPERAII_H
