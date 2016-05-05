// String.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "MyString.h"
int main()
{
	std::istringstream ss("mama papa");
	std::string str;
	ss >> str >> str;
	std::cout << str;
    return 0;
}

