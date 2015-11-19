// vec.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "functions.h"

using namespace std;

/* ������� 2: ������ ������� ������� ������ ���� ������� �� ����������� ������� ��������� ������� */


int main()
{
	vector<string> input = GetVectorOfStrings();
	if (!isDigitValues(input)) {
		cout << "Input contains non digit values" << endl;
		return -1;
	}
	vector<float> float_vec = StringVecToFloatVec(input);
	MultiplyValueByTheMin(float_vec);
	SortVector(float_vec);
	PrintVector(float_vec);
	return 0;
}
