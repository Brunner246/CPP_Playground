//
// Created by michael.brunner on 20/10/2023.
//

#include <iostream>
#include <map>
#include <algorithm>
#include "ObserverMain.h"
#include "CWeatherData.h"
#include "TObserver.h"

void observerMain()
{
    using WeatherObserver = TObserver<CWeatherData, CWeatherData::EWeatherData>;

	using MeteoSchweiz = TObserver<CWeatherData, CWeatherData::EWeatherData>;

	std::function<void(const CWeatherData&, const CWeatherData::EWeatherData)> lOnUpdateEvent = [](const CWeatherData& aSubject, const CWeatherData::EWeatherData aState)
	{
		switch (aState)
		{
		case CWeatherData::TEMPERATURE_changed:
			std::cout << "Temperature changed to " << aSubject.getTemperature() << std::endl;
			break;
		case CWeatherData::HUMIDITY_changed:
			std::cout << "Humidity changed to " << aSubject.getHumidity() << std::endl;
			break;
		case CWeatherData::PRESSURE_changed:
			std::cout << "Pressure changed to " << aSubject.getPressure() << std::endl;
			break;
		default:
			break;
		}
	};

	struct CMeteoChangeRecord
	{
		std::map<CWeatherData::EWeatherData, std::vector<float>> mChangeRecord{};

		void print()
		{
			std::ranges::for_each(mChangeRecord, [](auto const& aPair)
			{
				std::cout << "Change Record for " << aPair.first << std::endl;
				std::ranges::for_each(aPair.second, [](auto const& aValue)
				{
					std::cout << aValue << "; ";
				});
				std::cout << std::endl;
			});
		}
	};

	auto lMeteoChangeRecord = CMeteoChangeRecord();

	auto lOnUpdateEventMeteoCH = [&lMeteoChangeRecord](CWeatherData const& aSubject, const CWeatherData::EWeatherData aChange) -> void
	{
		switch (aChange)
		{
		case CWeatherData::TEMPERATURE_changed:
			lMeteoChangeRecord.mChangeRecord[aChange].push_back(aSubject.getTemperature());
			break;
		case CWeatherData::HUMIDITY_changed:
			lMeteoChangeRecord.mChangeRecord[aChange].push_back(aSubject.getHumidity());
			break;
		case CWeatherData::PRESSURE_changed:
			lMeteoChangeRecord.mChangeRecord[aChange].push_back(aSubject.getPressure());
			break;
		default:
			break;
		}
	};

	auto lObserver = WeatherObserver(lOnUpdateEvent);
	auto lMeteoCH = MeteoSchweiz(lOnUpdateEventMeteoCH);

	CWeatherData lWeatherData;
	lWeatherData.registerObserver(lObserver);
	lWeatherData.registerObserver(lMeteoCH);

	// lWeatherData.setMeasurements(10.0F, 20.0F, 30.0F);
	lWeatherData.setTemperature(11.0F);
	lWeatherData.setHumidity(21.0F);

	CWeatherData lWeatherData2;
	lWeatherData2.registerObserver(lObserver);
	lWeatherData2.registerObserver(lMeteoCH);

	// lWeatherData2.setMeasurements(12.0F, 22.0F, 32.0F);
	lWeatherData2.setTemperature(13.0F);
	lWeatherData2.setHumidity(23.0F);

	lMeteoChangeRecord.print();
}