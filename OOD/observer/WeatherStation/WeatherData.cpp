#include "WeatherData.h"

CWeatherData::CWeatherData()
	:m_temperature(0.0), m_humidity(0.0), m_pressure(760.0)
{

}

// ����������� � �������� �������
double CWeatherData::GetTemperature()const
{
	return m_temperature;
}
// ������������� ��������� (0...100)
double CWeatherData::GetHumidity()const
{
	return m_humidity;
}
// ����������� �������� (� ��.��.��)
double CWeatherData::GetPressure()const
{
	return m_pressure;
}

void CWeatherData::MeasurementsChanged()
{
	NotifyObservers();
}

void CWeatherData::SetMeasurements(double temp, double humidity, double pressure)
{
	humidity = humidity;
	m_temperature = temp;
	pressure = pressure;

	MeasurementsChanged();
}

SWeatherInfo CWeatherData::GetChangedData()const
{
	SWeatherInfo info;
	info.temperature = GetTemperature();
	info.humidity = GetHumidity();
	info.pressure = GetPressure();
	return info;
}