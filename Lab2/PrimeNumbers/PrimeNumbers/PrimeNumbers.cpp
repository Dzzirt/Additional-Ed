// PrimeNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PrimeNumbersUtils.h"

using namespace std;

const size_t MaxNumber = 100000000;


int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Usage: <upper bound>" << endl;
		return 1;
	}
	try
	{
		size_t inputNum = stoi(argv[1]);
		if (inputNum > MaxNumber)
		{
			throw std::invalid_argument("Upper bound should be equal or less than 100 000 000.");
		}
		set<int> primeNumbers = GeneratePrimeNumbersSet(inputNum);
		PrintSet(primeNumbers);
	}
	catch(std::invalid_argument & err)
	{
		cout << err.what() << endl;
		return 1;
	}
	
	return 0;
}

