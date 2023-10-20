//
// Created by michael.brunner on 20/10/2023.
//

#include "CWeatherData.h"

void CWeatherData::setMeasurements(float aTemperature, float aHumidity, float aPressure)
{
	mTemperature = aTemperature;
	mHumidity = aHumidity;
	mPressure = aPressure;
	notifyObservers(TEMPERATURE_changed);
	notifyObservers(HUMIDITY_changed);
	notifyObservers(PRESSURE_changed);
}

bool CWeatherData::registerObserver(WeatherDataObser &aObserver)
{
	auto [pos, success] = mObservers.insert(&aObserver);
	return success;
}

bool CWeatherData::removeObserver(WeatherDataObser &aObserver)
{
	return (mObservers.erase(&aObserver) > 0U);
}

void CWeatherData::notifyObservers(const CWeatherData::EWeatherData aData) const
{
	for (auto &observer: mObservers) {
		observer->update(*this, aData);
	}
}

void CWeatherData::setTemperature(const float aTemperature)
{
	mTemperature = aTemperature;
	notifyObservers(TEMPERATURE_changed);
}

void CWeatherData::setHumidity(const float aHumidity)
{
	mHumidity = aHumidity;
	notifyObservers(HUMIDITY_changed);
}

void CWeatherData::setPressure(const float aPressure)
{
	mPressure = aPressure;
	notifyObservers(PRESSURE_changed);
}
