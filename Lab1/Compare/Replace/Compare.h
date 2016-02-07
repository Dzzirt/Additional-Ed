#include "string"

// Function compares the content of two files line by line.
// Returns the index of the first line with the differences, or std::npos if there are no differences
size_t compare(const std::string & firstFileName, const std::string & secondFileName);