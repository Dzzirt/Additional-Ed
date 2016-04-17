#pragma once
#include "Observer.h"
#include "WeatherInfo.h"

using namespace std;

class CWeatherData : public CObservable<SWeatherInfo>
{
public:
	// Температура в градусах Цельсия
	CWeatherData();
	double GetTemperature()const;
	// Относительная влажность (0...100)
	double GetHumidity()const;
	// Атмосферное давление (в мм.рт.ст)
	double GetPressure()const;

	void MeasurementsChanged();

	void SetMeasurements(double temp, double humidity, double pressure);
protected:
	SWeatherInfo GetChangedData()const override;
private:
	double m_temperature;
	double m_humidity;	
	double m_pressure;	
};
