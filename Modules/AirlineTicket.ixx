//
// Created by michael.brunner on 12/10/2023.
//

module;
#include <iostream>
#include <utility>

export module airline_ticket;

export class AirlineTicket
{
public:
	AirlineTicket()
	{
		name = "Unknown";
		km = 0;
		isPremium = false;
	};

	[[nodiscard]] int getKm() const { return km; };
	void setKm(int distance) { km = distance; };

	[[nodiscard]] std::string getName() const { return name; };
	void setName (std::string nameString) { name = std::move(nameString); };

	[[nodiscard]] bool getIsPremium() const { return isPremium; };
	void setIsPremium(bool status) { isPremium = status; };

	[[nodiscard]] double price() const
	{
		if(isPremium)
			return 0;
		else
			return double( getKm() * 0.20 );
	};
private:
	std::string name;
	int km;
	bool isPremium;
};
