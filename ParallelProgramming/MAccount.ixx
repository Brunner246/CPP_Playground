//
// Created by michael.brunner on 12/10/2023.
//

export module MAccount;

import <mutex>;

export namespace BankAccount{
	class CAccount
	{
	public:

		std::mutex m_mutex{};

		CAccount() = default;

		explicit CAccount(int balance) : m_balance(balance) {}

		[[nodiscard]] int getBalance() const { return m_balance; }

		void deposit(int amount)
		{
		//	std::lock_guard<std::mutex> lock(m_mutex); // this ends-up in deadlock
			m_balance += amount;
		}

		void withdraw(int amount)
		{
			//std::lock_guard<std::mutex> lock(m_mutex); // this ends-up in deadlock
			m_balance -= amount;
		}

	private:
		int m_balance{0};
	};

	void transferMoney(CAccount& from, CAccount& to, int amount)
	{
		auto lLock1 = std::unique_lock<std::mutex>(from.m_mutex, std::defer_lock);
		auto lLock2 = std::unique_lock<std::mutex>(to.m_mutex, std::defer_lock);

		std::lock(lLock1, lLock2); // lock both unique locks without deadlock at same time

		from.withdraw(amount);
		to.deposit(amount);
	}

}