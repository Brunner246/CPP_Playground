//
// Created by michael.brunner on 17/09/2023.
//

#ifndef CPP_PLAYGROUND_CUSER_H
#define CPP_PLAYGROUND_CUSER_H

#include <string>

namespace Heap {
	class CUser final
	{
	public:
		CUser() = delete;

		explicit CUser(const std::string &aName);

		CUser(const CUser &aOther);

		CUser(CUser &&aOther) noexcept;

		CUser &operator=(const CUser &aOther);

		CUser &operator=(CUser &&aOther) noexcept;

		~CUser() noexcept;

		std::string toString() const noexcept;

		const std::string& getName() const noexcept;

		void setName(const std::string& aName) noexcept;

		void setDtorMessage(const std::string& aMessage) noexcept;

	private:
		std::unique_ptr<std::string> mName;
		std::string mDtorMessage;
	};
}

#endif //CPP_PLAYGROUND_CUSER_H
