#include "string"
#include "vector"
#include <algorithm>
#include "climits"

template <typename T> bool IsBetween(const T& value, const T& lowerBound, const T& upperBound);

template <typename T> bool IsWithinRangeInclusive(const T& value, const T& lowerBound, const T& upperBound);

//Function transfer value from source to destination notation in radix [2, 36) 
// Each symbol of value must be lower than source notation
//Returns string value of transfer result if transfer was complete of empty string if not
std::string Transfer(int sourceNotation, int destNotaion, const std::string & value);

void ValidationOfValue(const std::string &value, int sourceNotation);

void ValidationOfNotation(int notation);

//Function transfer value from source notation to decimal notation
int ToDecimalNotation(const std::string & value, int sourceNotation);

//Function transfer value from decimal notation to destination notation
std::string FromDecimalToDestination(int value, int destNotaion);

int CharToNumber(char character);

void AddWithOverflowCheck(int val1, int val2);
void MultiplicationWithOverflowCheck(int val1, int val2);