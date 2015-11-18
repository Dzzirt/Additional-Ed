// FlipBytes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <bitset>

using namespace std;

bool IsByte(const string& str)
{
	string::const_iterator iter = str.begin();
	while (iter != str.end() && isdigit(*iter))
	{
		++iter;
	}
	if (iter == str.end())
	{
		return atoi(str.c_str()) < 256 && atoi(str.c_str()) >= 0;
	}
	return false;
}

unsigned long Flip(string str)
{
	bitset<8> dig = atoi(str.c_str());
	for (size_t i = 0; i < 4; i++)
	{
		bool temp = dig[i];
		dig[i] = dig[7 - i];
		dig[7 - i] = temp;
	}
	return dig.to_ulong();
}

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Usage: flipbyte.exe <input byte>" << endl;
	}
	else
	{
		if (IsByte(argv[1]))
		{
			cout << Flip(argv[1]) << endl;
		}
		else
		{
			cout << "Please input correct value (0 - 255)" << endl;
		}
	}
	return 0;
}
