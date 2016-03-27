#pragma once
class CCar
{
public:
	CCar();
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);
	int GetGear(int gear);
	int GetSpeed();
	bool isTurnedOn();
	~CCar();
};

