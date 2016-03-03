// HtmlEncode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "HtmlEncode.h"
#include <iostream>



int _tmain(int argc, _TCHAR* argv[])
{
	std::string source;
	source = ReadIntoString();
	std::string result = HtmlEncode(source);
	PrintString(result);
	return 0;
}

