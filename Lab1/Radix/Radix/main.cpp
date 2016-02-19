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
	try
	{
		int sourceNotation = stoi(argv[1]);
		int destNotation = stoi(argv[2]);
		ValidationOfNotation(sourceNotation);
		ValidationOfNotation(destNotation);
		string value = argv[3];
		cout << Transfer(sourceNotation, destNotation, value) << endl;
	}
	catch (invalid_argument const& err)
	{
		cout << err.what() << endl;
		return 1;
	}
	catch (underflow_error const& err)
	{
		cout << err.what() << endl;
		return 1;
	}
	catch (overflow_error const& err)
	{
		cout << err.what() << endl;
		return 1;
	}
	return 0;
}

