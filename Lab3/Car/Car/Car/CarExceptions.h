#pragma once
#include <boost/variant.hpp>
#include <iostream>
#include <exception>

struct GearsDirectionsNotCompatible : public std::exception
{
	virtual const char* what() const throw() override
	{
		return  "You need to stop the car to change direction";
	}
};

struct GearsSpeedNotCompatible : public std::exception
{
	virtual const char* what() const throw() override
	{
		return  "To change gear current speed should be supported by current gear and new gear";
	}
};

struct GearIsOutOfRange : public std::exception
{
	virtual const char* what() const throw() override
	{
		return  "You can change gear from -1 to 5 only";
	}
};

struct GearChangingWhenEngineTurnedOff : public std::exception
{
	virtual const char* what() const throw() override
	{
		return  "When engine is turned off you can only change gear to 0";
	}
};

struct IncreasingSpeedOnNeutral : public std::exception
{
	virtual const char* what() const throw() override
	{
		return  "You can only decrease speed on neutral gear";
	}
};

struct ChangingSpeedWhenEngineTurnedOff : public std::exception
{
	virtual const char* what() const throw() override
	{
		return  "You cant change speed when engine is turned off";
	}
};

struct SettingNegativeSpeed : public std::exception
{
	virtual const char* what() const throw() override
	{
		return  "Speed must have positive value";
	}
};

struct TurningEngineOnAgain : public std::exception
{
	virtual const char* what() const throw() override
	{
		return  "You cant turn engine on if already turned on";
	}
};

struct SpeedIsOutOfGearRange : public std::exception
{
	virtual const char* what() const throw() override
	{
		return  "Speed must be in range of permissible values for current gear";
	}
};

struct CannotTurnOffEngine : public std::exception
{
	virtual const char* what() const throw() override
	{
		return  "Engine can be turned off only with zero speed on neutral gear";
	}
};