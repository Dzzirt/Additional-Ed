#include "StatsDisplay.h"


void StatsDisplay::Update(SWeatherInfo const& data)
{
	temperature.Update(data.temperature);
	humidity.Update(data.humidity);
	pressure.Update(data.pressure);
	temperature.PrintStats("Temperature");
	humidity.PrintStats("Humidity");
	pressure.PrintStats("Pressure");
}