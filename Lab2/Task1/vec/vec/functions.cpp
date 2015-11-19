#include "stdafx.h"
#include "functions.h"
using namespace boost;
using namespace std;

bool IsDigits(const string &str) {
	bool with_or_without_dot = (count(str.begin(), str.end(), '.') == 1 || count(str.begin(), str.end(), '.') == 0);
	return str.find_first_not_of("0123456789.") == string::npos && with_or_without_dot;
}

vector<string> GetVectorOfStrings() {
	string arr;
	getline(cin, arr);
	vector<string> vecOfStrings;
	split(vecOfStrings, arr, is_any_of(" "));
	return vecOfStrings;
}

void SortVector(vector<float> & float_vec)
{
	sort(float_vec.begin(), float_vec.end());
}

bool IsDigitValues(const vector<string>& input)
{
	for (vector<string>::const_iterator it = input.begin(); it != input.end(); ++it) {
		string val = *it;
		if (!IsDigits(val)) {
			return false;
		}
	}
	return true;
}

vector<float> StringVecToFloatVec(const vector<string> & input)
{
	vector<float> float_vec;
	for (vector<string>::const_iterator it = input.begin(); it != input.end(); ++it) {
		string value = *it;
		float_vec.push_back(atof(value.c_str()));
	}
	return float_vec;
}

void MultiplyValueByTheMin(vector<float> & input)
{
	float min_value = *min_element(input.begin(), input.end());
	for (vector<float>::iterator it = input.begin(); it != input.end() ; ++it) {
		float val = *it;
		*it = val * min_value;
	}
}

void PrintVector(const vector<float>& float_vec)
{
	for (vector<float>::const_iterator it = float_vec.begin(); it != float_vec.end(); ++it) {
		cout << *it;
		if (it != float_vec.end() - 1) {
			cout << " ";
		}
		else {
			cout << endl;
		}
	}
}