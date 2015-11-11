// FlipBytes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <bitset>

int main(int argc, char* argv[])
{
	std::bitset<8> dig = atoi(argv[1]); // 00000110
	for (size_t i = 0; i < 4; i++) {
		bool temp = dig[i];
		dig[i] = dig[7 - i];
		dig[7 - i] = temp;
	}
	std::cout << dig.to_ulong() << std::endl;

    return 0;
}

