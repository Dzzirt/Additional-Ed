// ExpressionConverter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ExpressionConverter.h"
using namespace std;
int main()
{
	CExpressionConverter conv;
	try
	{
		cout << conv.ToSuffixNotation(" 2  +   10   * (  ( 1   +   2)  *    3)/2+  3-2") << endl;
		cout << conv.ToSuffixNotation(" 2  +   10   * (  ( 1   +   2  *    3)/2+  3-2") << endl;
	}
	catch (const exception& ex)
	{
		cout << ex.what() << std::endl;
	}
    return 0;
}

