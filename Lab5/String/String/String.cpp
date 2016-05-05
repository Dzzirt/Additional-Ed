// String.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
int main()
{
	std::string kek("lkl \0 lkl", 9);
	auto str2 = kek + "1";
	std::cout << kek << std::endl;
    return 0;
}

