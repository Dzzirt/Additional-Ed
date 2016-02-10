#include "string"
#include "vector"
#include <algorithm>
#include "climits"
//Function transfer value from source to destination notation in radix [2, 36) 
// Each symbol of value must be lower than source notation
//Returns string value of transfer result if transfer was complete of empty string if not
std::string Transfer(int sourceNotation, int destNotaion, const std::string & value);

long long ToDecimalNotation(const std::string & value, int sourceNotation);

std::string FromDecimalToDestination(long long value, int destNotaion);