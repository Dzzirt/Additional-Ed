#pragma once
#include "Observer.h"
#include "WeatherInfo.h"
#include "Statistic.h"
class StatsDisplay : public IObserver<SWeatherInfo>
{
private:
	/* ����� Update ������ ���������, ����� ���������� ����������� ��� ������ ��������
	������ CObservable �� ����� �������� ��� �����, �.�. � ���������� IObserver ��
	�������� ���������
	*/
	void Update(SWeatherInfo const& data) override;

	CStatistic temperature;
	CStatistic humidity;
	CStatistic pressure;

};

