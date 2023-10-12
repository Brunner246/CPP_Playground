//
// Created by michael.brunner on 12/10/2023.
//
module;

export module ModuleExample;

import <iostream>;
import <string>;
import <vector>;


export import airline_ticket;
export import math;

export namespace ModuleExample {
	void print(const std::string &str)
	{
		std::cout << str << std::endl;
	}

	void print(const std::vector<int> &vec)
	{
		for (const auto &item: vec) {
			std::cout << item << std::endl;
		}
	}

	void print(const AirlineTicket &ticket)
	{
		std::cout << "Name: " << ticket.getName() << std::endl;
		std::cout << "Km: " << ticket.getKm() << std::endl;
		std::cout << "Premium: " << ticket.getIsPremium() << std::endl;
		std::cout << "Price: " << ticket.price() << std::endl;
	}

	void print(const std::vector <AirlineTicket> &tickets)
	{
		for (const auto &ticket: tickets) {
			print(ticket);
		}
	}

	int add(int fir, int sec)
	{
		return math::add(fir, sec);
	}

	int getProduct(const std::vector<int>& vec)
	{
		return math::getProduct(vec);
	}
}


