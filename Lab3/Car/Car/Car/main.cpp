// Car.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CarUI.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CCar car;
	CCarUI carUi(car, std::cin, std::cout);
	carUi.Exec();
	return 0;
}

