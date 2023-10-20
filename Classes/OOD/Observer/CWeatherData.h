//
// Created by michael.brunner on 20/10/2023.
//

#ifndef CPP_PLAYGROUND_CWEATHERDATA_H
#define CPP_PLAYGROUND_CWEATHERDATA_H


#include <set>
#include "TObserver.h"

class CWeatherData
{
public:
	enum EWeatherData
	{
		TEMPERATURE_changed,
		HUMIDITY_changed,
		PRESSURE_changed
	};

	using WeatherDataObser = TObserver<CWeatherData, EWeatherData>;

	CWeatherData() = default;

	void setMeasurements(float aTemperature, float aHumidity, float aPressure);

	void setTemperature(float aTemperature);

	void setHumidity(float aHumidity);

	void setPressure(float aPressure);

	float getTemperature() const { return mTemperature; }

	float getHumidity() const { return mHumidity; }

	float getPressure() const { return mPressure; }

	bool registerObserver(WeatherDataObser& aObserver);

	bool removeObserver(WeatherDataObser& aObserver);

	void notifyObservers(EWeatherData aData) const;



private:
	float mTemperature{};

	float mHumidity{};

	float mPressure{};

	std::set<WeatherDataObser*> mObservers{};

};


#endif //CPP_PLAYGROUND_CWEATHERDATA_H
