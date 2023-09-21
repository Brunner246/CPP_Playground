//
// Created by michael.brunner on 21/09/2023.
//

module ;

#include "IButton.h"

export module TestModule;

import <functional>;
import <stdexcept>;
import <thread>;

namespace TestModule
{
	export class CButton : public IButton
	{
	public:
		explicit CButton(std::function<void(void)> &&aOnClick)
				: mOnClick{std::move(aOnClick)}
		{
			if (!mOnClick) {
				throw std::invalid_argument("mOnClick is not set");
			}
		}

		~CButton() override = default;

		void onClick() override
		{
			mOnClick();
		}

	private:
		std::function<void(void)> mOnClick;
	};

	namespace Sleep
	{
		export void sleep(int aSeconds)
		{
			std::this_thread::sleep_for(std::chrono::seconds(aSeconds));
		}
	}
}



