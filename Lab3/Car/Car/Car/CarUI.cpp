#include "stdafx.h"
#include "CarUI.h"
#include "Car.h"

using namespace std;
using namespace std::placeholders;

CCarUI::CCarUI(CCar & car, std::istream & input, std::ostream & output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "Info", bind(&CCarUI::GetInfo, this, _1) },
		{ "EngineOn", bind(&CCarUI::TurnOnEngine, this, _1) },
		{ "EngineOff", bind(&CCarUI::TurnOffEngine, this, _1) },
		{ "SetGear", bind(&CCarUI::SetGear, this, _1) },
		{ "SetSpeed", bind(&CCarUI::SetSpeed, this, _1) },
		{ "Help", bind(&CCarUI::PrintHelp, this, _1) },
})
{
}
void CCarUI::Exec()
{
	PrintHelp(m_input);
	GetInfo(m_input);
	while (!cin.eof() && !cin.fail())
	{
		if (!HandleCommand())
		{
			m_output << "Unknown Command!" << endl;
		}
	}
}

void CCarUI::PrintHelp(std::istream & args)
{
	m_output << "--------------Help----------------" << endl
		<< "EngineOn - turning on car engine" << endl
		<< "EngineOff - turning off car engine" << endl
		<< "SetGear <value> - setting car gear" << endl
		<< "SetSpeed <value> - setting car speed" << endl
		<< "Info - shows current car state" << endl
		<< "Help - shows commands info" << endl
		<< "--------------Help----------------" << endl;
}
bool CCarUI::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	std::vector<string, string> binaryCmd;
	boost::split(binaryCmd, commandLine, bind2nd(std::equal_to<char>(), ' '));
	auto it = m_actionMap.find(binaryCmd[0]);
	if (it != m_actionMap.end())
	{
		try
		{
			if (binaryCmd.size() == 2)
			{
				it->second(istringstream(binaryCmd[1]));
			}
			else if (binaryCmd.size() == 1)
			{
				it->second(istringstream(binaryCmd[0]));
			}
		}
		catch (std::exception const& err)
		{
			cout << err.what() << endl;
		}
		return true;
	}
	return false;
}

void CCarUI::TurnOnEngine(std::istream & args)
{
	m_car.TurnOnEngine();
	m_output << "Car is turned on" << endl;
}

void CCarUI::TurnOffEngine(std::istream & args)
{
	m_car.TurnOffEngine();
	m_output << "TV is turned off" << endl;
}

void CCarUI::SetSpeed(std::istream & args)
{
	string line;
	getline(args, line);
	m_car.SetSpeed(stoi(line));
	m_output << "Speed changed" << endl;
}

void CCarUI::SetGear(std::istream & args)
{
	string line;
	getline(args, line);
	m_car.SetGear(stoi(line));
	m_output << "Gear changed" << endl;
}

void CCarUI::GetInfo(std::istream & args)
{
	m_output << "--------------Info----------------" << endl
		<< "Engine is on: " << m_car.IsTurnedOn() << endl
		<< "Direction: " << m_car.GetDirection() << endl
		<< "Speed: " << m_car.GetSpeed() << endl
		<< "Gear: " << m_car.GetGear() << endl
		<< "--------------Info----------------" << endl;
}
