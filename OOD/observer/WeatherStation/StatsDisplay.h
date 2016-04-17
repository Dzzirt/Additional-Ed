#pragma once
#include "Observer.h"
#include "WeatherInfo.h"
#include "Statistic.h"
class StatsDisplay : public IObserver<SWeatherInfo>
{
private:
	/* Метод Update сделан приватным, чтобы ограничить возможность его вызова напрямую
	Классу CObservable он будет доступен все равно, т.к. в интерфейсе IObserver он
	остается публичным
	*/
	void Update(SWeatherInfo const& data) override;

	CStatistic temperature;
	CStatistic humidity;
	CStatistic pressure;

};

