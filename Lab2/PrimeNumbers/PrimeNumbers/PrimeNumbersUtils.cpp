#include "stdafx.h"
#include "PrimeNumbersUtils.h"

using namespace std;

void PrintSet(std::set<int> & set)
{
	for (auto & prime : set)
	{
		cout << prime << endl;
	}
}

std::set<int> GeneratePrimeNumbersSet(unsigned upperBound)
{
	set<int> prime;
	vector<bool> primeNumbers(upperBound + 1, true);
	int step = 1;
	for (size_t i = 2; i * i <= upperBound; i += step)
	{
		if (i == 3)
		{
			step = 2;
		}
		if (primeNumbers[i])
		{
			for (size_t j = i * i; j <= upperBound; j += 2 * i)
			{
				if (j + i <= upperBound)
				{
					primeNumbers[j + i] = false;
				}
				primeNumbers[j] = false;
			}
		}
	}
	for (size_t i = 2; i < primeNumbers.size(); i++)
	{
		if (primeNumbers[i])
		{
			prime.insert(prime.end(), i);
		}
	}
	return std::move(prime);
}
