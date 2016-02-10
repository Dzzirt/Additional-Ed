#include "iostream"
#include "Transfer.h"
using namespace std;


int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		cout << "Usage: radix.exe <source notation> <destination notation> <value>" << endl;
		return 1;
	}
	cout << Transfer(34, 33, "2147483647") << endl;
	return 0;
}

