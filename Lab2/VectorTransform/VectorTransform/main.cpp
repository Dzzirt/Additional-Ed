// Разделить элементы массива на половину максимального элемента
//

#include "stdafx.h"

#include "TransformUtils.h"
#include "iostream"

using namespace std;



int main(int argc, char* argv[])
{
	cout << "Input float values separated by space. After all input any of non digit symbol on new line to stop reading" << endl;
	auto numbers = ReadInVector();
	Transform(numbers);
	Sort(numbers);
	PrintSeparatedByComma(numbers);


	return 0;
}

