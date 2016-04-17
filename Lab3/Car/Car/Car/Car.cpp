#include "stdafx.h"
#include "Car.h"

std::map<int, std::pair<int, int>> CCar::m_speedRanges = {
	{ -1, { 0, 20 } },
	{ 0, { 0, 150 } },
	{ 1, { 0, 30 } },
	{ 2, { 20, 50 } },
	{ 3, { 30, 60 } },
	{ 4, { 40, 90 } },
	{ 5, { 50, 150 } }
};
CCar::CCar()
	:m_gear(0), m_speed(0), m_isTurnedOn(false), m_state(STOP), m_speedRanges({
		{ -1, { 0, 20 } },
		{ 0, { 0, 150 } },
		{ 1, { 0, 30 } },
		{ 2, { 20, 50 } },
		{ 3, { 30, 60 } },
		{ 4, { 40, 90 } },
		{ 5, { 50, 150 } }
})
{
}


void CCar::TurnOnEngine()
{
	if (m_isTurnedOn)
	{
		throw TurningEngineOnAgain();
	}
	m_isTurnedOn = true;
}

void CCar::TurnOffEngine()
{
	if (m_gear != 0 && m_speed != 0)
	{
		throw CannotTurnOffEngine();
	}
	m_isTurnedOn = false;

}

bool CCar::IsGearsDirectionCompatible(int gear1, int gear2)
{
	if (gear1 == -1 && m_speed != 0 && gear2 == 1)
	{
		return false;
	}
	if (gear1 == 1 && gear2 == -1 && m_speed != 0)
	{
		return false;
	}
	if (gear1 == 0 && gear2 == 1 && m_state == BACKWARD)
	{
		return false;
	}
	if (gear1 == 0 && gear2 == -1 && m_state == FORWARD)
	{
		return false;
	}
	return true;
}

void CCar::SetGear(int gear)
{
	if (!isGearSupported(gear))
	{
		throw GearIsOutOfRange();
	}
	if (!IsGearsSpeedCompatible(m_gear, gear))
	{
		throw GearsSpeedNotCompatible();
	}
	if (!IsGearsDirectionCompatible(m_gear, gear))
	{
		throw GearsDirectionsNotCompatible();
	}		
	if (m_isTurnedOn || gear == 0)
	{
		if (gear > 0)
		{
			m_state = FORWARD;
		}
		else if (gear < 0)
		{
			m_state = BACKWARD;
		}
		m_gear = gear;
	}
	else
	{
		throw GearChangingWhenEngineTurnedOff();
	}

}

void CCar::SetSpeed(int speed)
{
	if (speed < 0)
	{
		throw SettingNegativeSpeed();
	}
	if (m_gear == 0 && m_speed < speed)
	{
		throw IncreasingSpeedOnNeutral();
	}
	if (m_isTurnedOn)
	{
		if (speed == 0)
		{
			m_state = STOP;
		}
		auto range = m_speedRanges.at(m_gear);
		if (range.first <= speed && range.second >= speed)
		{
			m_speed = speed;
		}
		else
		{
			throw SpeedIsOutOfGearRange();
		}
	}
	else
	{
		throw ChangingSpeedWhenEngineTurnedOff();
	}

}

int CCar::GetGear() const
{
	return m_gear;
}

int CCar::GetSpeed() const
{
	return m_speed;
}

bool CCar::IsTurnedOn() const
{
	return m_isTurnedOn;
}

MovementState CCar::GetDirection() const
{
	return m_state;
}

bool CCar::IsGearsSpeedCompatible(int gear1, int gear2)
{
	auto gearRange1 = m_speedRanges.at(gear1);
	auto gearRange2 = m_speedRanges.at(gear2);
	if (gearRange1.first <= m_speed && gearRange2.first <= m_speed
		&& gearRange1.second >= m_speed && gearRange2.second >= m_speed)
	{
		return true;
	}
	return false;
}

bool CCar::isGearSupported(int newGear)
{
	if (newGear > 5 || newGear < -1)
	{
		return false;
	}
	return true;
}
