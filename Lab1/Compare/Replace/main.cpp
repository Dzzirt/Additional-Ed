#include "iostream"
#include "Compare.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Usage: compare.exe <file1.txt> <file2.txt>" << endl;
		return 1;
	}
	string first(argv[1]);
	string second(argv[2]);
	auto pos = Compare(first, second);
	if (pos != string::npos)
	{
		cout << "Files are different.Line number is " << pos << endl;
	}
	else
	{
		cout << "Files are equal" << endl;
	}
	return 0;
}