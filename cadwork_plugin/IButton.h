//
// Created by michael.brunner on 21/09/2023.
//

#ifndef CPP_PLAYGROUND_IBUTTON_H
#define CPP_PLAYGROUND_IBUTTON_H

namespace TestModule
{
	class IButton
	{
	public:
		virtual ~IButton() = default;

		virtual void onClick() = 0;
	};
}

#endif //CPP_PLAYGROUND_IBUTTON_H
